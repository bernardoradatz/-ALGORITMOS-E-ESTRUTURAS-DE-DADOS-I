#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_NOME 50
#define TAMANHO_EMAIL 50
#define TAMANHO_CONTATO (TAMANHO_NOME + sizeof(int) + TAMANHO_EMAIL)

#define ESCOLHA_MENU 0 
#define CONTAGEM_AGENDA (ESCOLHA_MENU + sizeof(int))
#define LOOP_I (CONTAGEM_AGENDA + sizeof(int))
#define INDICE_ENCONTRADO (LOOP_I + sizeof(int))
#define LER_IDADE (INDICE_ENCONTRADO + sizeof(int))
#define LER_NOME (LER_IDADE + sizeof(int))
#define LER_EMAIL (LER_NOME + TAMANHO_NOME)
#define TAMANHO_CABECALHO (LER_EMAIL + TAMANHO_EMAIL) 
#define INICIO_AGENDA TAMANHO_CABECALHO



int* pMenu(void* pBuffer) { 
    return (int*)((char*)pBuffer + ESCOLHA_MENU); 
}
int* pContagemAgenda(void* pBuffer) { 
    return (int*)((char*)pBuffer + CONTAGEM_AGENDA); 
}
int* pLoopI(void* pBuffer) { 
    return (int*)((char*)pBuffer + LOOP_I); 
}
int* pIndiceTemporario(void* pBuffer) { 
    return (int*)((char*)pBuffer + INDICE_ENCONTRADO); 
}
int* pIdadeTemporaria(void* pBuffer) { 
    return (int*)((char*)pBuffer + LER_IDADE); 
}
char* pNomeTemporario(void* pBuffer) { 
    return (char*)pBuffer + LER_NOME; 
}
char* pEmailTemporario(void* pBuffer) { 
    return (char*)pBuffer + LER_EMAIL; 
}
void* pAgendaInicio(void* pBuffer) { 
    return (void*)((char*)pBuffer + INICIO_AGENDA); 
}
char* pNomeContato(void* pBuffer, int* pIndice) {
    return (char*)pAgendaInicio(pBuffer) + (*pIndice * TAMANHO_CONTATO);
}
int* pIdadeContato(void* pBuffer, int* pIndice) {
    return (int*)((char*)pAgendaInicio(pBuffer) + (*pIndice * TAMANHO_CONTATO) + TAMANHO_NOME);
}
char* pEmailContato(void* pBuffer, int* pIndice) {
    return (char*)pAgendaInicio(pBuffer) + (*pIndice * TAMANHO_CONTATO) + TAMANHO_NOME + sizeof(int);
}

void* AdicionarPessoa(void *pBuffer);
void* RemoverPessoa(void *pBuffer); 
void BuscarPessoa(void *pBuffer); 
void ListarTodos(void *pBuffer); 
void encontrarIndicePeloNome(void *pBuffer);

int main() {
    void *pBuffer = malloc(INICIO_AGENDA);
    if (pBuffer == NULL) { 
        return 1; 
    }
    memset(pBuffer, 0, INICIO_AGENDA);
    *pContagemAgenda(pBuffer) = 0;

    do{
        printf("\n--- Agenda ---\n");
        printf("1. Adicionar \n2. Remover\n3. Buscar\n4. Listar\n5. Sair\n");
        printf("Opção: ");
        
        if (scanf("%d", pMenu(pBuffer)) != 1) {
            while (getchar() != '\n' && !feof(stdin));
            *pMenu(pBuffer) = 0;
        } else {
            while (getchar() != '\n');
        }

        switch (*pMenu(pBuffer)) {
            case 1: 
                pBuffer = AdicionarPessoa(pBuffer); 
                break;
            case 2: 
                pBuffer = RemoverPessoa(pBuffer);   
                break; 
            case 3: 
                BuscarPessoa(pBuffer);              
                break;
            case 4: 
                ListarTodos(pBuffer);               
                break;
            case 5: 
                printf("Menu encerrado.\n");              
                break; 
            default: 
                printf("Opção inválida.\n");       
                break;
        }
    } while (*pMenu(pBuffer) != 5);
    
    free(pBuffer);
    return 0;
}


void* AdicionarPessoa(void *pBuffer) {
    printf("Nome: ");
    fgets(pNomeTemporario(pBuffer), TAMANHO_NOME, stdin);
    pNomeTemporario(pBuffer)[strcspn(pNomeTemporario(pBuffer), "\n")] = 0;

    printf("Idade: ");
    while (scanf("%d", pIdadeTemporaria(pBuffer)) != 1) {
        while (getchar() != '\n');
        printf("Idade inválida! \nDigite novamente: ");
    }
    while (getchar() != '\n');

    printf("Email: ");
    fgets(pEmailTemporario(pBuffer), TAMANHO_EMAIL, stdin);
    pEmailTemporario(pBuffer)[strcspn(pEmailTemporario(pBuffer), "\n")] = 0;

    *pLoopI(pBuffer) = INICIO_AGENDA + (*pContagemAgenda(pBuffer) + 1) * TAMANHO_CONTATO;
    
    void *pNewBuffer = realloc(pBuffer, (size_t)*pLoopI(pBuffer));
    if (pNewBuffer == NULL) {
        printf("Falha ao alocar memória!\n");
        return pBuffer; 
    }
    pBuffer = pNewBuffer; 
    
    strcpy(pNomeContato(pBuffer, pContagemAgenda(pBuffer)), pNomeTemporario(pBuffer));
    *pIdadeContato(pBuffer, pContagemAgenda(pBuffer)) = *pIdadeTemporaria(pBuffer);
    strcpy(pEmailContato(pBuffer, pContagemAgenda(pBuffer)), pEmailTemporario(pBuffer));
    (*pContagemAgenda(pBuffer))++; 
    printf("Contato adicionado!\n");
    return pBuffer; 
}

void encontrarIndicePeloNome(void *pBuffer) {
    *pIndiceTemporario(pBuffer) = -1; 
    *pLoopI(pBuffer) = 0; 
    
    while (*pLoopI(pBuffer) < *pContagemAgenda(pBuffer)) {
        if (strcmp(pNomeTemporario(pBuffer), pNomeContato(pBuffer, pLoopI(pBuffer))) == 0) {
            *pIndiceTemporario(pBuffer) = *pLoopI(pBuffer); 
            break; 
        }
        (*pLoopI(pBuffer))++;
    }
}

void* RemoverPessoa(void *pBuffer) {
    if (*pContagemAgenda(pBuffer) == 0) {
        printf("Agenda vazia.\n");
        return pBuffer; 
    }

    printf("Nome para remover: ");
    fgets(pNomeTemporario(pBuffer), TAMANHO_NOME, stdin);
    pNomeTemporario(pBuffer)[strcspn(pNomeTemporario(pBuffer), "\n")] = 0;

    encontrarIndicePeloNome(pBuffer);

    if (*pIndiceTemporario(pBuffer) == -1) {
        printf("Contato não encontrado.\n");
        return pBuffer; 
    }

    *pLoopI(pBuffer) = INICIO_AGENDA + (*pContagemAgenda(pBuffer) - 1) * TAMANHO_CONTATO;
    
    void *novoBuffer = malloc((size_t)*pLoopI(pBuffer));
    if (novoBuffer == NULL) {
        printf("Falha ao alocar memória!\n");
        return pBuffer;
    }

    memcpy(novoBuffer, pBuffer, INICIO_AGENDA);

    *pIdadeTemporaria(pBuffer) = *pIndiceTemporario(pBuffer) * TAMANHO_CONTATO;
    if (*pIdadeTemporaria(pBuffer) > 0) {
        memcpy(pAgendaInicio(novoBuffer), 
               pAgendaInicio(pBuffer),  
               (size_t)*pIdadeTemporaria(pBuffer));
    }

    *pLoopI(pBuffer) = (*pContagemAgenda(pBuffer) - 1) - *pIndiceTemporario(pBuffer);
    *pIdadeTemporaria(pBuffer) = *pLoopI(pBuffer) * TAMANHO_CONTATO;
    
    if (*pIdadeTemporaria(pBuffer) > 0) {
        void* pDestino = (char*)pAgendaInicio(novoBuffer) + (*pIndiceTemporario(pBuffer) * TAMANHO_CONTATO);
        void* pOrigem = (char*)pAgendaInicio(pBuffer) + (*pIndiceTemporario(pBuffer) + 1) * TAMANHO_CONTATO;
        memcpy(pDestino, pOrigem, (size_t)*pIdadeTemporaria(pBuffer));
    }

    free(pBuffer);

    (*pContagemAgenda(novoBuffer))--;
    printf("Contato removido!\n");

    return novoBuffer;
}


void BuscarPessoa(void *pBuffer) {
    if (*pContagemAgenda(pBuffer) == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    printf("Nome para buscar: ");
    fgets(pNomeTemporario(pBuffer), TAMANHO_NOME, stdin);
    pNomeTemporario(pBuffer)[strcspn(pNomeTemporario(pBuffer), "\n")] = 0;

    encontrarIndicePeloNome(pBuffer);

    if (*pIndiceTemporario(pBuffer) != -1) {

        *pLoopI(pBuffer) = *pIndiceTemporario(pBuffer);

        printf("\n--- Contato Encontrado ---\n");
        printf("Nome: %s\n", pNomeContato(pBuffer, pLoopI(pBuffer)));
        printf("Idade: %d\n", *pIdadeContato(pBuffer, pLoopI(pBuffer)));
        printf("Email: %s\n", pEmailContato(pBuffer, pLoopI(pBuffer)));
    } else {
        printf("Contato não encontrado.\n");
    }
}

void ListarTodos(void *pBuffer) {
    if (*pContagemAgenda(pBuffer) == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    printf("\n--- Listando contatos ---\n");
    
    *pLoopI(pBuffer) = 0;
    while (*pLoopI(pBuffer) < *pContagemAgenda(pBuffer)) {
        printf("\n--- Contato %d ---\n", *pLoopI(pBuffer) + 1);
        printf("Nome: %s\n", pNomeContato(pBuffer, pLoopI(pBuffer)));
        printf("Idade: %d\n", *pIdadeContato(pBuffer, pLoopI(pBuffer)));
        printf("Email: %s\n", pEmailContato(pBuffer, pLoopI(pBuffer)));
        (*pLoopI(pBuffer))++; 
    }
}