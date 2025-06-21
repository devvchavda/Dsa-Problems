class Solution {
public:
    char reqCh(char s){
        if(s=='('){
            return ')';
        }
        else if(s=='{'){
            return '}';
        }
        else if(s=='['){
            return ']';
        }
        return 'o';
    }
    bool isValid(string s) {
        stack<char> st ; 

        for(char i : s){
            if(st.empty()){
                if(i=='(' or i=='{' or i=='['){
                    st.push(i);
                }
                else{
                    return false ; 
                }
            }
            else{
                if(i=='(' or i=='{' or i=='['){
                    st.push(i);
                }
                else{
                    if(reqCh(st.top()) == i){
                        st.pop();
                    }
                    else{
                        return false ; 
                    }
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};