class FrontMiddleBackQueue {

    private List<Integer> queue;

    public FrontMiddleBackQueue() {
        this.queue = new ArrayList<>();
    }
    
    public void pushFront(int val) {
        queue.add(0, val);
    }
    
    public void pushMiddle(int val) {
        queue.add(getMiddle(true), val);
    }
    
    public void pushBack(int val) {
        queue.add(val);
    }
    
    public int popFront() {
        if (queue.isEmpty()) return -1;
        int val = queue.get(0);
        queue.remove(0);
        return val;
    }
    
    public int popMiddle() {
        if (queue.isEmpty()) return -1;
        int val = queue.get(getMiddle(false));
        queue.remove(getMiddle(false));
        return val;
    }
    
    public int popBack() {
        if (queue.isEmpty()) return -1;
        int val = queue.get(queue.size() - 1);
        queue.remove(queue.size() - 1);
        return val;
    }

    private int getMiddle(boolean insert) {
        int middle = Math.min(queue.size(), Math.max(0, (queue.size()  - 1) / 2 + (insert && queue.size() % 2 == 0 ? 1 : 0)));
        return middle;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */