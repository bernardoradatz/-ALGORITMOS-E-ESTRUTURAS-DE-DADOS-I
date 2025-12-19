bool isValid(char * s) {
    int n = strlen(s);
    if (n == 0) return true;

    char *stack = (char *)malloc(n * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char topChar = stack[top];
            
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '[')) {
                top--;
            } else {
                free(stack);
                return false; 
            }
        }
    }
    
    bool result = (top == -1);
    free(stack);
    return result;
}