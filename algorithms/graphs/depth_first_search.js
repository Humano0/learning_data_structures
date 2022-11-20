/*  ----- ITERATIVE ------
const depthFirstSearch = (graph, source) => {
    const stack = [ source ]
    while(stack.length > 0){
        const current = stack.pop()
        console.log(current)
        for(let neighbor of graph[current]){
            stack.push(neighbor)
        }
    }
}
*/

// ----- RECURSION -----
const depthFirstSearch = (graph, source) => {
    console.log(source)
    for(let neighbor of graph[source]){
        depthFirstSearch(graph, neighbor)
    }
}

const graph = {
    a: ['b', 'c'],
    b: ['d'],
    c: ['b'],
    d: ['f', 'e'],
    e: [],
    f: []
}

depthFirstSearch(graph, 'a')
