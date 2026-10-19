class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() { mini = LLONG_MAX; }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
        } else if (value >= mini) {
            st.push(value);
        } else {
            long long val = 2 * (long long)value - mini;
            mini = value;
            st.push(val);
        }
    }

    void pop() {
        if (st.top() < mini) {
            int newMini = 2 * mini - st.top();
            mini = newMini;
        }
        st.pop();
    }

    int top() { return (st.top() >= mini) ? st.top() : mini; }

    int getMin() { return mini; }
};