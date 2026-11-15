    #include <stdio.h>
    #include <ctype.h>
    char stack[10];
    int top=0;
    int max=10;
    void push(char x)
    {
        if(top==(max))
        {
            printf("Stack overflow");
        }
        else
        {
            stack[top++]=x;
        }
    }
    char pop()
    {
        if(top==0)
        {
            printf("Stack underflow");
            return 0;
        }
        else
        {
            char x=stack[--top];
            return x;
        }
    }
    char peek()
    {
        return stack[top-1];
    }
    int estack[10];
    int etop=0;
    int emax=10;
    void epush(int x)
    {
        if(etop==(emax))
        {
            printf("Stack overflow");
        }
        else
        {
            estack[etop++]=x;
        }
    }
    int epop()
    {
        if(etop==0)
        {
            printf("Stack underflow");
            return 0;
        }
        else
        {
            int x=estack[--etop];
            return x;
        }
    }
    int epeek()
    {
        return estack[etop-1];
    }
    int prec(char x)
    {
        if(x=='^')
        {
            return 3;
        }
        else if(x=='*' || x=='/') 
        {
            return 2;
        }
        else if(x=='+' || x=='-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int main()
    {
        stack[top++]='#';
        int n=0,i=0,j=0;
        printf("Enter length of string: ");
        scanf("%d",&n);
        char is[n+1];
        char ps[n+1];
        is[n]='\0';
        ps[n]='\0';
        printf("Enter string: ");
        scanf("%s",is);
        for(i=0;i<n;i++)
        {
            if(isalnum(is[i]))
            {
                ps[j++]=is[i];
            }
            else if(is[i]=='(')
            {
                push(is[i]);
            }
            else if(is[i]==')')
            {
                while(1)
                {
                    char x=pop();
                    if(x=='(')
                    {
                        break;
                    }
                    else
                    {
                        ps[j++]=x;
                    }
                }
            }
            else
            {
                while(peek()!='#' && peek()!='(' && (prec(is[i])<prec(peek()) || (prec(is[i])==prec(peek()) && is[i]!='^')))
                {
                    ps[j++]=pop();
                }
                push(is[i]);
            }
        }
        while(peek()!='#')
        {
            ps[j++]=pop();
        }
        ps[j]='\0';
        printf("Postfix expression: ");
        printf("%s\n",ps);
        for(i=0;ps[i]!='\0';i++)
        {
            if(isalnum(ps[i]))
            {
                epush(ps[i]-'0');
            }
            else
            {
                int x=epop();
                int y=epop();
                int z=0;
                if(ps[i]=='+')
                {
                    z=x+y;
                }else if(ps[i]=='-')
                {
                    z=y-x;
                }else if(ps[i]=='*')
                {
                    z=x*y;
                }else if(ps[i]=='/')
                {
                    if(x==0)
                    {
                        printf("Error: Division by 0");
                        return 1;
                    }
                    else
                    {
                        z=y/x;
                    }
                }
                else
                {
                    z=1;
                    while(x!=0)
                    {
                        z=z*y;
                        x--;
                    }
                }
                epush(z);
            }
        }
        if(etop!=1)
        {
            printf("Invalid expression");
            return 1;
        }
        int a=epop();
        printf("Result: %d\n",a);
        return 0;
    }