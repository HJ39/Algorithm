import Foundation

struct Stack<T> {
    private var stack: [T] = []
    var count: Int { stack.count }
    var top: T? { stack.last }
    var isEmpty: Bool { stack.isEmpty }
    
    mutating func push(_ element: T){
        stack.append(element)
    }
    
    mutating func pop() -> T? {
        isEmpty ? nil : stack.popLast()
    }
}

var st = Stack<Int>()

print("====== PUSH ======")
for cnt in 0...10 {
    print(cnt)
    st.push(cnt)
}

print("====== POP ======")
for _ in 0...10 {
    print(st.pop() ?? 0)
}
