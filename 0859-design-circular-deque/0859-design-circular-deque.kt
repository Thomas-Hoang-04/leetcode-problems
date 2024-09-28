class MyCircularDeque(k: Int) {
    private val queue: IntArray = IntArray(k) { 0 }; 
    private var front: Int = 0;
    private var back: Int = k - 1;
    private var size: Int = 0;
    private val cap: Int = k;

    fun insertFront(value: Int): Boolean {
        if (isFull()) return false;
        front = (front - 1 + cap) % cap;
        queue[front] = value;
        size++;
        return true
    }

    fun insertLast(value: Int): Boolean {
        if (isFull()) return false;
        back = (back + 1) % cap;
        queue[back] = value;
        size++;
        return true
    }

    fun deleteFront(): Boolean {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }

    fun deleteLast(): Boolean {
        if (isEmpty()) return false;
        back = (back - 1 + cap) % cap;
        size--;
        return true;
    }

    fun getFront(): Int {
        return if (isEmpty()) -1 else queue[front];
    }

    fun getRear(): Int {
        return if (isEmpty()) -1 else queue[back];
    }

    fun isEmpty(): Boolean {
        return size == 0;
    }

    fun isFull(): Boolean {
        return size == cap;
    }

}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */