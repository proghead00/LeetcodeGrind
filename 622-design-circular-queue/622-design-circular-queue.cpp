class MyCircularQueue {
private:
    int maxSize, front = 0, rear = -1;
    vector<int> q;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        maxSize = k;
    }

    bool enQueue(int val) {
        if (isFull()) return false;
        rear = (++rear) % maxSize;
        q[rear] = val;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) front = 0, rear = -1;
        else front = (++front) % maxSize;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    bool isEmpty() {
        return rear == -1;
    }
    bool isFull() {
        return !isEmpty() && (rear + 1) % maxSize == front;
    }

};