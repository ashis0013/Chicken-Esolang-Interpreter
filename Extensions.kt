fun <T> MutableList<T>.pop(): T {
    return this.removeAt(this.size - 1)
}

fun Boolean.toInt() = if (this) 1 else 0