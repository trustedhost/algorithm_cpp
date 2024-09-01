#include <iostream>
#include <stack>

int main() {
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    while ( !st.empty() ){
        std::cout << st.top()<< '\n';
        st.pop();
    }
    std::cout << std::endl;

//--------vector version--------

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    while ( !vec.empty() ) {
        std::cout << vec[vec.size() - 1] << '\n';
        vec.pop_back();
    }
    std::cout << std::endl;
    return 0;
}
