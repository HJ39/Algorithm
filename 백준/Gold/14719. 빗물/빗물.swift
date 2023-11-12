import Foundation

let HW = readLine()!.split(separator: " ").map{Int(String($0))!}
let (H,W) = (HW[0], HW[1])
let input = readLine()!.split(separator: " ").map{Int(String($0))!}

var cnt = 0
var first = input[0]

for i in 0..<W {
    first = max(first , input[i])
    var last = 0
    for j in i..<W {
        last = max(last, input[j])
    }
    
    let minHeight = min(first, last)
    if input[i] != first && input[i] != last {
        cnt += minHeight - input[i]
    }
    
}

print(cnt)