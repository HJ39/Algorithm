import Foundation

let NM = readLine()!.split(separator: " ").map{Int($0)!}
let (N, M) = (NM[0], NM[1])

var input = (0..<N).map{_ in readLine()!.split(separator: " ").map{Int($0)!}}
var direct = [(0,1),(1,0),(0,-1),(-1,0)]    // 동, 남, 서, 북
var q: [(Int, Int, Int)] = []
var res = 987654321

func direction(dir: Int, x: Int, y: Int) {
    var (x,y) = (x,y)
    let dir = dir % 4

    while true {
        let mx = direct[dir].0 + x
        let my = direct[dir].1 + y
        x = mx
        y = my
        guard mx >= 0 && mx < N && my >= 0 && my < M else { return }
        if input[mx][my] == 6 {return}
        guard input[mx][my] == 0 else {continue}
        input[mx][my] = -1
    }
}

func cal(cnt: Int) {
    
    if cnt == q.count {
        var notCnt = 0
        
        for i in 0..<N {
            for j in 0..<M {
                if input[i][j] == 0 {
                    notCnt += 1
                }
            }
        }
        res = min(res, notCnt)
        return
    }
    
    var backup = input
    let (x,y,type) = (q[cnt].0, q[cnt].1, q[cnt].2)
    
    for i in 0..<4 {
        backup = input
        
        switch type {
        case 1:
            direction(dir: i, x: x, y: y)
        case 2:
            direction(dir: i, x: x, y: y)
            direction(dir: i+2, x: x, y: y)
        case 3:
            direction(dir: i, x: x, y: y)
            direction(dir: i+1, x: x, y: y)
        case 4:
            direction(dir: i, x: x, y: y)
            direction(dir: i+1, x: x, y: y)
            direction(dir: i+2, x: x, y: y)
        case 5:
            direction(dir: i, x: x, y: y)
            direction(dir: i+1, x: x, y: y)
            direction(dir: i+2, x: x, y: y)
            direction(dir: i+3, x: x, y: y)
        default:
            break
        }
        
        cal(cnt: cnt+1)
        
        input = backup
        
    }
    
    
}

func sol() {
    
    for i in 0..<N {
        for j in 0..<M {
            if input[i][j] != 0 && input[i][j] != 6 {
                q.append((i,j,input[i][j]))
            }
        }
    }
    cal(cnt: 0)
    
}

sol()
print(res)
