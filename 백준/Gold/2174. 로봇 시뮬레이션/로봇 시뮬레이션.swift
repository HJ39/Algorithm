import Foundation

let AB = readLine()!.split(separator: " ").map{Int(String($0))!}
let (A,B) = (AB[0], AB[1])

let NM = readLine()!.split(separator: " ").map{Int(String($0))!}
let (N,M) = (NM[0], NM[1])

struct Robot {
    var x, y, type: Int
    var dir: String
    
    mutating func chanage(x:Int, y:Int) {
        self.x = x
        self.y = y
    }
    
    mutating func chanageDir(dir: String) {
        self.dir = dir
    }
}

struct Order {
    var robotType, repeatCnt: Int
    var dir: String
}

var pos = [Robot]()
var order = [Order]()

for i in 0..<N {
    let input = readLine()!.split(separator: " ").map{String($0)}
    pos.append(Robot(x: Int(input[0])!, y: Int(input[1])!, type: i+1, dir: input[2]))
}

for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map{String($0)}
    order.append(Order(robotType: Int(input[0])!, repeatCnt: Int(input[2])!, dir: input[1]))
}

func sol(){
    for _ in 0..<M {
        let order = order.removeFirst()
        let robotPos = pos[order.robotType-1]
        
        if order.dir == "F" {
            if !front(robotPos, order) {
                return
            }
        } else if order.dir == "R" {
            right(robotPos, order)
        } else if order.dir == "L" {
            left(robotPos, order)
        }
    }
    print("OK")
}

func front(_ robot: Robot, _ order: Order) -> Bool {
    var robot = robot
    for _ in 0..<order.repeatCnt {
        if robot.dir == "N" {
            robot.y += 1
            
            for j in 0..<pos.count {
                guard j != order.robotType-1 else {continue}
                
                if pos[j].x == robot.x && pos[j].y == robot.y {
                    print("Robot \(order.robotType) crashes into robot \(pos[j].type)")
                    return false
                }
            }
            
            if robot.y > B {
                print("Robot \(order.robotType) crashes into the wall")
                return false
            }
            robot.chanage(x: robot.x, y: robot.y)
            pos[order.robotType-1] = robot
        } else if robot.dir == "W" {
            robot.x -= 1
            
            for j in 0..<pos.count {
                guard j != order.robotType-1 else {continue}
                
                if pos[j].x == robot.x && pos[j].y == robot.y {
                    print("Robot \(order.robotType) crashes into robot \(pos[j].type)")
                    return false
                }
            }
            
            if robot.x <= 0 {
                print("Robot \(order.robotType) crashes into the wall")
                return false
            }
            robot.chanage(x: robot.x, y: robot.y)
            pos[order.robotType-1] = robot
        } else if robot.dir == "E"{
            robot.x += 1
            
            for j in 0..<pos.count {
                guard j != order.robotType-1 else {continue}
                
                if pos[j].x == robot.x && pos[j].y == robot.y {
                    print("Robot \(order.robotType) crashes into robot \(pos[j].type)")
                    return false
                }
            }
            
            if robot.x > A {
                print("Robot \(order.robotType) crashes into the wall")
                return false
            }
            robot.chanage(x: robot.x, y: robot.y)
            pos[order.robotType-1] = robot
        } else if robot.dir == "S"{
            robot.y -= 1
            
            for j in 0..<pos.count {
                guard j != order.robotType-1 else {continue}
                
                if pos[j].x == robot.x && pos[j].y == robot.y {
                    print("Robot \(order.robotType) crashes into robot \(pos[j].type)")
                    return false
                }
            }
            
            if robot.y <= 0 {
                print("Robot \(order.robotType) crashes into the wall")
                return false
            }
            robot.chanage(x: robot.x, y: robot.y)
            pos[order.robotType-1] = robot
        }
    }
    return true
}

func left(_ robot: Robot, _ order: Order) {
    var robot = robot
    for _ in 0..<order.repeatCnt {
        if robot.dir == "N" {
            robot.dir = "W"
        } else if robot.dir == "W" {
            robot.dir = "S"
        } else if robot.dir == "E"{
            robot.dir = "N"
        } else if robot.dir == "S"{
            robot.dir = "E"
        }
    }
    pos[order.robotType-1] = robot
}

func right(_ robot: Robot, _ order: Order) {
    var robot = robot
    for _ in 0..<order.repeatCnt {
        if robot.dir == "N" {
            robot.dir = "E"
        } else if robot.dir == "W" {
            robot.dir = "N"
        } else if robot.dir == "E"{
            robot.dir = "S"
        } else if robot.dir == "S"{
            robot.dir = "W"
        }
    }
    pos[order.robotType-1] = robot
}

sol()
