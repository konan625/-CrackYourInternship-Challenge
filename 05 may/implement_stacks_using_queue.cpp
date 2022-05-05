// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
class MyStack {
public:
    queue<int> q;
    queue<int> temp;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q.size()==0){
            q.push(x);
        }else{
           while(!q.empty()){
               temp.push(q.front());
               q.pop();
           }
            q.push(x);
            while(!temp.empty()){
                q.push(temp.front());
                temp.pop();
            }
        }
    }
    
    int pop() {
         int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */