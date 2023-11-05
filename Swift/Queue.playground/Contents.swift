import Foundation

struct Queue<T> {
    private var queue: [T?] = []
    private var head: Int = 0
    var count: Int { queue.count }
    var isEmpty: Bool { queue.isEmpty }
    var front: T? { queue[head] }
    
    mutating func push(_ element: T) {
        queue.append(element)
    }
    
    mutating func pop() -> T? {
        guard head < queue.count, let element = queue[head] else { return nil }
        queue[head] = nil
        head += 1
        
        if head > 50 {
            queue.removeFirst(head)
            head = 0
        }
        return element
    }
}

var q = Queue<Int>()

print("====== PUSH ======")
for cnt in 0...60 {
    print(cnt)
    q.push(cnt)
}

print("====== POP ======")
for _ in 0...60 {
    print(q.pop() ?? 0)
}
