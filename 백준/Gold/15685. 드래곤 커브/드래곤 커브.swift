import Foundation

let N = Int(readLine()!)!
let dxy = [(1,0),(0,-1),(-1,0),(0,1)]
var direct: [Int] = []
var map = Array(repeating: Array(repeating: 0, count: 102), count: 102)
var (x,y,d,g) = (0,0,0,0)

func turn() {
    for i in direct.reversed() {
        let dir = (i + 1) % 4
        x += dxy[dir].0
        y += dxy[dir].1
        map[x][y] = 1
        direct.append(dir)
    }
}

func sol(){
    for _ in 0..<N {
        let input = readLine()!.split(separator: " ").map{Int($0)!}
        (x,y,d,g) = (input[0], input[1], input[2], input[3])
        direct = []
        
        
        map[x][y] = 1
        x += dxy[d].0
        y += dxy[d].1
        map[x][y] = 1
        direct.append(d)
        for _ in 0..<g {
            turn()
        }
    }
    var cnt = 0
    for i in 0...100 {
        for j in 0...100 {
            guard map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1 else {continue}
            cnt += 1
        }
    }
    print(cnt)
}

sol()
