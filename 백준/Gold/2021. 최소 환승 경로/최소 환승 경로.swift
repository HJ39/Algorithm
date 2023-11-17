import Foundation

struct Queue<T> {
    private var queue: [T?] = []
    var count: Int { queue.count }
    var isEmpty: Bool { queue.isEmpty }
    var head: Int = 0
    
    mutating func push(_ element: T) {
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

let NM = readLine()!.split(separator: " ").map{Int($0)!}
let (N, L) = (NM[0], NM[1])
var input = Array(repeating: [Int](), count: 200001)
var q = Queue<(Int,Int)>()
let MAX = 100000
var check = Array(repeating: -1, count: 200001)

for i in 1...L {
    _ = readLine()!.split(separator: " ").map{
        if Int($0)! == -1 {return}
        input[Int($0)!].append(i + MAX)
        input[i + MAX].append(Int($0)!)
    }
}

let se = readLine()!.split(separator: " ").map{Int($0)!}
let (s, e) = (se[0], se[1])

func bfs() -> Int {
    q.push((-1, s))
    
    while !q.isEmpty {
        guard let (cnt, cur) = q.pop() else { break }
        for i in 0..<input[cur].count {
            let next = input[cur][i]
            if check[next] > -1 {continue}
            
            if next > MAX {
                q.push((cnt+1, next))
                check[next] = cnt + 1
            }
            else if next == e {
                return cnt
            }
            else{
                q.push((cnt, next))
                check[next] = cnt
            }
        }
        
    }
    return -1
}

print(bfs())
