import Foundation

var wheel1 = readLine()!.map{Int(String($0))!}
var wheel2 = readLine()!.map{Int(String($0))!}
var wheel3 = readLine()!.map{Int(String($0))!}
var wheel4 = readLine()!.map{Int(String($0))!}

let K = Int(readLine()!)!
var check: [Bool] = Array(repeating: false, count: 3)

for _ in 0..<K {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let (num, dir) = (input[0], input[1])
    
    checkingList()
    
    switch num {
    case 1:
        firstCase(num, dir)
    case 2:
        secondCase(num, dir)
    case 3:
        thirdCase(num, dir)
    case 4:
        lastCase(num, dir)
    default:
        break
    }
}
print(wheel1[0] + (wheel2[0] * 2) + (wheel3[0] * 4) + (wheel4[0] * 8))
func checkingList() {
    
    check[0] = true
    if wheel1[2] == wheel2[6] {
        check[0] = false
    }
    
    check[1] = true
    if wheel2[2] == wheel3[6] {
        check[1] = false
    }
    
    check[2] = true
    if wheel3[2] == wheel4[6] {
        check[2] = false
    }
}

func firstCase(_ num: Int, _ dir: Int) {
    if dir == 1 {
        let last = wheel1.popLast()!
        wheel1.insert(last, at: 0)
    } else {
        let first = wheel1.removeFirst()
        wheel1.append(first)
    }
    
    for i in 0..<3 {
        if !check[i] {
            return
        }
        if dir == 1{
            switch i {
            case 0:
                let first = wheel2.removeFirst()
                wheel2.append(first)
            case 1:
                let last = wheel3.popLast()!
                wheel3.insert(last, at: 0)
            case 2:
                let first = wheel4.removeFirst()
                wheel4.append(first)
            default:
                break
            }
        } else {
            switch i {
            case 0:
                let last = wheel2.popLast()!
                wheel2.insert(last, at: 0)
            case 1:
                let first = wheel3.removeFirst()
                wheel3.append(first)
            case 2:
                let last = wheel4.popLast()!
                wheel4.insert(last, at: 0)
            default:
                break
            }
        }
        
    }
}

func secondCase(_ num: Int, _ dir: Int) {
    if dir == 1 {
        let last = wheel2.popLast()!
        wheel2.insert(last, at: 0)
    } else {
        let first = wheel2.removeFirst()
        wheel2.append(first)
    }
    
    if check[0] {
        if dir == 1 {
            let first = wheel1.removeFirst()
            wheel1.append(first)
        } else {
            let last = wheel1.popLast()!
            wheel1.insert(last, at: 0)
        }
    }
    
    for i in 1..<3 {
        if !check[i] {
            return
        }
        if dir == 1{
            switch i {
            case 1:
                let first = wheel3.removeFirst()
                wheel3.append(first)
            case 2:
                let last = wheel4.popLast()!
                wheel4.insert(last, at: 0)
            default:
                break
            }
        } else {
            switch i {
            case 1:
                let last = wheel3.popLast()!
                wheel3.insert(last, at: 0)
            case 2:
                let first = wheel4.removeFirst()
                wheel4.append(first)
            default:
                break
            }
        }
        
    }
}

func thirdCase(_ num: Int, _ dir: Int) {
    if dir == 1 {
        let last = wheel3.popLast()!
        wheel3.insert(last, at: 0)
    } else {
        let first = wheel3.removeFirst()
        wheel3.append(first)
    }
    
    if check[2] {
        if dir == 1 {
            let first = wheel4.removeFirst()
            wheel4.append(first)
        } else {
            let last = wheel4.popLast()!
            wheel4.insert(last, at: 0)
        }
    }
    
    for i in (0..<2).reversed() {
        if !check[i] {
            return
        }
        if dir == 1{
            switch i {
            case 0:
                let last = wheel1.popLast()!
                wheel1.insert(last, at: 0)
            case 1:
                let first = wheel2.removeFirst()
                wheel2.append(first)
            default:
                break
            }
        } else {
            switch i {
            case 0:
                let first = wheel1.removeFirst()
                wheel1.append(first)
            case 1:
                let last = wheel2.popLast()!
                wheel2.insert(last, at: 0)
            default:
                break
            }
        }
        
    }
}

func lastCase(_ num: Int, _ dir: Int) {
    if dir == 1 {
        let last = wheel4.popLast()!
        wheel4.insert(last, at: 0)
    } else {
        let first = wheel4.removeFirst()
        wheel4.append(first)
    }
    
    for i in (0..<3).reversed() {
        if !check[i] {
            return
        }
        if dir == 1{
            switch i {
            case 0:
                let first = wheel1.removeFirst()
                wheel1.append(first)
            case 1:
                let last = wheel2.popLast()!
                wheel2.insert(last, at: 0)
            case 2:
                let first = wheel3.removeFirst()
                wheel3.append(first)
            default:
                break
            }
        } else {
            switch i {
            case 0:
                let last = wheel1.popLast()!
                wheel1.insert(last, at: 0)
            case 1:
                let first = wheel2.removeFirst()
                wheel2.append(first)
            case 2:
                let last = wheel3.popLast()!
                wheel3.insert(last, at: 0)
            default:
                break
            }
        }
        
    }
}