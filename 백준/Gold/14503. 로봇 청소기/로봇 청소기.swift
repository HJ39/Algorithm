import Foundation

struct Queue<T> {
    private var queue: [T?] = []
    private var head: Int = 0
    var count: Int { queue.count }
    var isEmpty: Bool {queue.isEmpty}
    
    mutating func push(_ element: T) {
        queue.append(element)
    }
    
    mutating func pop() -> T? {
        guard head < queue.count, let element = queue[head] else {return nil}
        queue[head] = nil
        head += 1
        
        if head > 1000 {
            queue.removeFirst(head)
            head = 0
        }
        return element
    }
}

let NM = readLine()!.components(separatedBy: " ").map{Int(String($0))!}
let (N,M) = (NM[0], NM[1])

let rcd = readLine()!.components(separatedBy: " ").map{Int(String($0))!}
let (r,c,d) = (rcd[0], rcd[1], rcd[2])

var input = (0..<N).map{_ in readLine()!.components(separatedBy: " ").map{Int(String($0))!}}
var q = Queue<(Int,Int,Int)>()
let dxy = [(-1,0),(0,1),(1,0),(0,-1)]

q.push((r,c,d))
input[r][c] = 2
var cnt = 1

func back(dir: Int) -> Int {
    switch dir {
    case 0: // 북
        return 2
    case 1: // 동
        return 3
    case 2: // 남
        return 0
    case 3: // 서
        return 1
    default:
        fatalError()
    }
}

func clean() {
    while !q.isEmpty {
        guard let top = q.pop() else { break }
        var dir = top.2
        var check = false
        
        for _ in 0...3 {
            dir -= 1
            if dir < 0 {
                dir = 3
            }
            let mx = dxy[dir].0 + top.0
            let my = dxy[dir].1 + top.1
            
            guard 0..<N ~= mx && 0..<M ~= my && input[mx][my] == 0 && !check else { continue }
            input[mx][my] = 2
            q.push((mx,my,dir))
            cnt += 1
            check = true
        }
        
        if !check {
            let backDir = back(dir: dir)
            let backX = dxy[backDir].0 + top.0
            let backY = dxy[backDir].1 + top.1
            
            if input[backX][backY] == 0 || input[backX][backY] == 2 {
                q.push((backX, backY, dir));
            }
        }
    }
}

clean()
print(cnt)
