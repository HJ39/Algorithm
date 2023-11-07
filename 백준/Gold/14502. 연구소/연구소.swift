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
        
        if head > 10000 {
            queue.removeFirst(head)
            head = 0
        }
        return element
    }
}

let NM = readLine()!.components(separatedBy: " ").map{Int(String($0))!}
let (N,M) = (NM[0], NM[1])
var input = (0..<N).map{_ in readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
var check = Array(repeating: Array(repeating: 0, count: M+1), count: N+1)
var q = Queue<(Int,Int)>()
var initQ: [(Int,Int)] = []

for i in 0..<N {
    for j in 0..<M {
        guard input[i][j] == 2 else { continue }
        initQ.append((i,j))
        q.push((i,j))
    }
}

func print(){
    for i in 0..<N {
        for j in 0..<M {
            print(check[i][j],separator: " ",terminator: " ")
        }
        print("",terminator: "\n")
    }
}


func build(_ cnt: Int) {
    if cnt == 3 { // 탐색 시작
        check = input
        bfs()
        initQ.forEach { q.push($0) }
        return
    }
    
    for i in 0..<N {
        for j in 0..<M {
            guard input[i][j] == 0 else { continue }
            input[i][j] = 1
            build(cnt+1)
            input[i][j] = 0
        }
    }
}

func bfs() {
    while !q.isEmpty{
        guard let top = q.pop() else {break}
        
        for i in [(0,1),(0,-1),(1,0),(-1,0)] {
            let (mx,my) = (i.0 + top.0, i.1 + top.1)
            guard 0..<N ~= mx && 0..<M ~= my && check[mx][my] == 0 else { continue }
            check[mx][my] = 2
            q.push((mx,my))
        }
    }
    
    find()
}

var maxCnt = 0
func find() {
    var cnt = 0
    for i in 0..<N {
        for j in 0..<M {
            guard check[i][j] == 0 else {continue}
            cnt += 1
        }
    }
    maxCnt = max(maxCnt, cnt)
}

check = input
build(0)
print(maxCnt)
