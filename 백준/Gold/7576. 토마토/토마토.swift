import Foundation

struct Queue<T> {
    var queue: [T?] = []
    var head: Int = 0
    var count: Int {queue.count}
    var isEmpty: Bool { queue.isEmpty }
    var front: T? { queue[head] }
    
    mutating func push(_ element: T){
        queue.append(element)
    }
    
    mutating func pop() -> T? {
        guard head < queue.count, let element = queue[head] else {return nil}
        
        queue[head] = nil
        head += 1
        
        if head > 1000000 {
            queue.removeFirst(head)
            head = 0
        }
        return element
    }
}

let num = readLine()!.components(separatedBy: " ").map{Int($0)!}
let (N, M) = (num[0], num[1])
var arr = (0..<M).map{_ in readLine()!.split(separator: " ").map{Int(String($0))!}}
var q = Queue<(Int, Int)>()

for x in 0..<M {
    for y in 0..<N {
        if arr[x][y] == 1 {
            q.push((x,y))
        }
    }
}

var res = 0
while !q.isEmpty {
    guard let top = q.pop() else {break}
    
    res = max(res, arr[top.0][top.1])
    
    for i in [(0,1),(0,-1),(1,0),(-1,0)]{
        let (mx, my) = (top.0 + i.0, top.1 + i.1)
        if 0..<M ~= mx && 0..<N ~= my && arr[mx][my] == 0{
            arr[mx][my] = arr[top.0][top.1] + 1
            q.push((mx,my))
        }
    }
}

let check = arr.flatMap{$0}.filter{$0 == 0}
check.isEmpty ? print(res - 1) : print(-1)
