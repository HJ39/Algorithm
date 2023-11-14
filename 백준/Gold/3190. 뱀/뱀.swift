import Foundation

let N = Int(readLine()!)!

struct Pos {
    let x, y: Int
}

struct Order {
    let time: Int
    let turn: String
}

struct SnakePos {
    var x, y: Int
    var dir: Int
}

struct deque<T> {
    var queue: [T] = []
    var isEmpty: Bool { queue.isEmpty }
    var count: Int { queue.count }
    var head: T? { queue[queue.count-1] }
    
    mutating func pushFront(_ element: T) { queue.insert(element, at: 0) }
    
    mutating func pushBack(_ element: T) { queue.append(element)}
    
    mutating func popBack() -> T? { return queue.popLast() }
    
    mutating func popFront() -> T? { return queue.removeFirst() }
}

let K = Int(readLine()!)!
var applePos: [Pos] = []
for _ in 0..<K {
    let pos = readLine()!.split(separator: " ").map{Int(String($0))!}
    applePos.append(Pos(x: pos[0], y: pos[1]))
}

let L = Int(readLine()!)!
var order: [Order] = []
for _ in 0..<L {
    let or = readLine()!.split(separator: " ").map{String($0)}
    order.append(Order(time: Int(or[0])!, turn: or[1]))
}

var q = deque<SnakePos>()

// N: 0, E: 1, S: 2, W: 3
let turning = [(-1,0),(0,1),(1,0),(0,-1)]
q.pushBack(SnakePos(x: 1, y: 1, dir: 1))
var time = 1

func sol(){
    while true {
        guard let head = q.head else { break }
        let (newX, newY) = (head.x + turning[head.dir].0, head.y + turning[head.dir].1)
        
        guard newX <= N && newX > 0 && newY <= N && newY > 0 else { return }
        
        var newDir = head.dir
        for i in 0..<L {
            if order[i].time == time {
                if order[i].turn == "L" {
                    newDir -= 1
                    if newDir < 0 {newDir = 3}
                } else if order[i].turn == "D" {
                    newDir += 1
                    if newDir > 3 {newDir = 0}
                }
            }
        }
        
        
        for i in 0..<q.count {
            if q.queue[i].x == newX && q.queue[i].y == newY {
                return
            }
        }
        
        let newSnakePos = SnakePos(x: newX, y: newY, dir: newDir)
        time += 1
        var flag = false
        for i in 0..<applePos.count {
            if applePos[i].x == newX && applePos[i].y == newY {
                applePos.remove(at: i)
                q.pushBack(newSnakePos)
                flag = true
                break
            }
        }


        if !flag {
            _ = q.popFront()
            q.pushBack(newSnakePos)
        }

        
    }
}

sol()
print(time)
