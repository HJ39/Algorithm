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
let N = num[0]
let M = num[1]
var arr = Array(repeating: Array(repeating: 0, count: M + 1), count: N + 1)
let dx = [0,0,1,-1]
let dy = [1,-1,0,0]

for i in 1...N {
    var list = [Int]()
    list.append(0)
    list.append(contentsOf: Array(readLine()!).map{Int(String($0))!})
    arr[i] = list
}

var q = Queue<(Int, Int)>()
func bfs() {
    q.push((1,1))
    arr[1][1] = 1
    
    while !q.isEmpty {
        guard let top = q.pop() else {continue}

        if top.0 == N && top.1 == M{
            print(arr[top.0][top.1])
            break
        }
        
        for i in 0...3 {
            let mx = top.0 + dx[i]
            let my = top.1 + dy[i]
            guard mx <= N && my <= M && mx >= 1 && my >= 1 else { continue }
            if arr[mx][my] == 1 {
                arr[mx][my] = arr[top.0][top.1] + 1
                q.push((mx,my))
            }
        }
    }
}

bfs()

