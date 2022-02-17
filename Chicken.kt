import java.io.File
import kotlin.system.exitProcess

val stack = mutableListOf<String>()

fun initStack(opcodes: List<Int>, input: String? = null) {
    stack.add("2")
    stack.add(input ?: "")
    stack.addAll(opcodes.map { it.toString() })
}

fun next(): Int {
    val idx = stack[0].toInt()
    stack[0] = (idx + 1).toString()
    return stack[idx].toInt()
}

fun debug(opLen: Int) {
    println("${stack[0]}: ${stack[stack[0].toInt()]}")
    println(stack.subList(opLen+2, stack.size))
}

fun addOp(b: String, a: String) : String {
    return if (a.toIntOrNull() == null || b.toIntOrNull() == null) {
        a + b
    } else (a.toInt() + b.toInt()).toString()
}

fun execute(op: Int, input: String? = null) {
    when (op) {
        0 -> exitProcess(0)
       1 -> stack.add("chicken")
        2 -> stack.add(addOp(stack.pop(), stack.pop()))
        3 -> stack.add((- stack.pop().toInt() + stack.pop().toInt()).toString())
        4 -> stack.add((stack.pop().toInt() * stack.pop().toInt()).toString())
        5 -> stack.add((stack.pop() == stack.pop()).toInt().toString())
        6 -> {
            val offset = stack.pop().toInt()
            stack.add(if (next() == 1) input?.get(offset).toString() else stack[offset])
        }
        7 -> {
            val offset = stack.pop().toInt()
            stack[offset] = stack.pop()
        }
        8 -> {
            val offset = stack.pop().toInt()
            val conditionElement = stack.pop()
            if (conditionElement.isNotEmpty() && conditionElement != "0") stack[0] = (stack[0].toInt() + offset).toString()
        }
        9 -> stack.add((stack.pop().toInt()).toChar().toString())
        else -> stack.add((op - 10).toString())
    }
}

fun run(opcodes: List<Int>, input: String? = null) {
    initStack(opcodes, input)
    while (stack[0].toInt() <= opcodes.size + 1) {
        val op = next()
        if (op == 0) break
        execute(op)
    }
    println(stack.last())
}


fun main(args: Array<String>) {
	if (args.isEmpty()) {
		println("Please enter a file path")
		return
	}
    val opcodes =
        File(args[0]).readLines().map { if (it.isBlank()) 0 else it.split(" ").size }.toMutableList()
    opcodes.add(0)
	run(opcodes, args.getOrNull(1))
} 
