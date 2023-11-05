import Foundation

struct Queue<T> {
    var queue: [T?] = []
    var head: Int = 0
    var count: Int {queue.count}
    var isEmpty: Bool { queue.isEmpty}
    
    mutating func push(_ element: T){
        queue.append(element)
    }
    
    mutating func pop() -> T? {
        guard head < queue.count, let element = queue[head] else {return nil}
        
        queue[head] = nil
        head += 1
        
        if head > 50 {
            queue.removeFirst(head)
            head = 0
        }
        return element
    }
}

let num = readLine()!.components(separatedBy: " ").map{Int($0)!}
let (N, M) = (num[0], num[1])
var arr = Array(repeating: Array(repeating: 0, count: M + 1), count: N + 1)

for i in 1...N {
    var list = [Int]()
    list.append(0)
    list.append(contentsOf: Array(readLine()!).map{Int(String($0))!})
    arr[i] = list
}

var q = Queue<(Int, Int)>()
q.push((1,1))
arr[1][1] = 1

while !q.isEmpty {
    guard let top = q.pop() else {continue}
    
    if top.0 == N && top.1 == M{
        print(arr[top.0][top.1])
        break
    }
    
    for i in [(0,1),(0,-1),(1,0),(-1,0)] {
        let (mx, my) = (top.0 + i.0, top.1 + i.1)
        if 1...N ~= mx && 1...M ~= my && arr[mx][my] == 1 {
            arr[mx][my] = arr[top.0][top.1] + 1
            q.push((mx,my))
        }
    }
}
