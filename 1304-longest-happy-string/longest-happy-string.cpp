class Node{
    public:
        char data;
        int count;
        Node(char ch ,int d){
            data = ch;
            count = d;
        }
};

class compare{
    public:
    bool operator()(Node a , Node b ){
        return a.count < b.count;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
         // creating the max heap 
        priority_queue<Node, vector<Node>,compare> maxHeap;

        // insert char & freq into maxheap
        if(a > 0){
            Node temp('a',a);
            maxHeap.push(temp);
        }

        if(b > 0){
            Node temp('b',b);
            maxHeap.push(temp);
        }

        if(c > 0){
            Node temp('c',c);
            maxHeap.push(temp);
        }

        string ans = "";

        while(maxHeap.size() > 1){
            Node first  = maxHeap.top(); maxHeap.pop();
            Node second = maxHeap.top(); maxHeap.pop();

            if(first.count >= 2){
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }else{
                ans += first.data;
                first.count--;
            }
            if(second.count >= 2 && second.count >= first.count// -> important condition fas jaoge yha 
            ){
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }else{
                ans += second.data;
                second.count--;
               
            }
            
             // push into the heap if count is not equal to 0
            if(first.count != 0 ){
                maxHeap.push(first);
            }
            if(second.count != 0){
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1){
            Node temp  = maxHeap.top(); maxHeap.pop();
             if(temp.count >= 2){
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }else{
                ans += temp.data;
                temp.count--;
            }  
        }

        return ans;
    }
};