import Foundation

let NM = readLine()!.split(separator: " ").map{Int($0)!}
let (N, M) = (NM[0], NM[1])
let input = (0..<N).map{_ in readLine()!.split(separator: " ").map{Int($0)!}}
var check = Array(repeating: Array(repeating: false, count: M+1), count: N+1)
var maxCnt = 0
let dxy = [(0,1),(0,-1),(-1,0),(1,0)]

func dfs(x: Int, y: Int, cnt: Int, sum: Int) {
    
    if cnt == 3 {
        maxCnt = max(maxCnt, sum)
        return
    }
    
    for dir in dxy {
        let mx = x + dir.0
        let my = y + dir.1
        
        guard mx >= 0 && mx < N && my >= 0 && my < M else {continue}
        
        if !check[mx][my] {
            check[mx][my] = true
            dfs(x: mx, y: my, cnt: cnt+1, sum: sum + input[mx][my])
            check[mx][my] = false
        }
    }
}

func shape1(i: Int, j: Int) { // ㅓ
    let sum = input[i][j] + input[i+1][j] + input[i+2][j] + input[i+1][j-1]
    maxCnt = max(maxCnt, sum)
}

func shape2(i: Int, j: Int) { // ㅗ
    let sum = input[i][j] + input[i][j+1] + input[i][j+2] + input[i-1][j+1]
    maxCnt = max(maxCnt, sum)
}

func shape3(i: Int, j: Int) { // ㅏ
    let sum = input[i][j] + input[i+1][j] + input[i+2][j] + input[i+1][j+1]
    maxCnt = max(maxCnt, sum)
}

func shape4(i: Int, j: Int) { // ㅜ
    let sum = input[i][j] + input[i][j+1] + input[i][j+2] + input[i+1][j+1]
    maxCnt = max(maxCnt, sum)
}


func sol(){
    
    for i in 0..<N {
        for j in 0..<M {
            check[i][j] = true
            dfs(x: i, y: j, cnt: 0, sum: input[i][j])
            check[i][j] = false
            if j-1 >= 0 && i+2 < N { shape1(i: i, j: j) }
            if i-1 >= 0 && j+2 < M { shape2(i: i, j: j) }
            if i+2 < N && j+1 < M { shape3(i: i, j: j) }
            if i+1 < N && j+2 < M { shape4(i: i, j: j) }
        }
    }
    
    print(maxCnt)
}

sol()
