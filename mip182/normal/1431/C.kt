// Thanks BenQ!
/* sorting
 * 1 (ok)
	val a = nextLongs().sorted() // a is mutable list
 * 2 (ok)
	val a = arrayListOf<Long>() // or ArrayList<Long>()
	a.addAll(nextLongs())
	a.sort()
 * 3 (ok)
	val A = nextLongs()
	val a = Array<Long>(n,{0})
	for (i in 0..n-1) a[i] = A[i]
	a.sort()
 * 4 (ok)
	val a = ArrayList(nextLongs())
	a.sort()
 * 5 (NOT ok, quicksort)
	val a = LongArray(N) // or nextLongs().toLongArray()
	Arrays.sort(a)
 */
/* 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
	intArrayOf(8, 9, 1, 13),
	intArrayOf(3, 12, 7, 5),
	intArrayOf(0, 2, 4, 11),
	intArrayOf(6, 10, 15, 14)
	)
 */
/* printing variables:
 * println("${l+1} and $r")
 * print d to 8 decimal places: String.format("%.8g%n", d)
 * try to print one stringbuilder instead of multiple prints
 */
/* comparing pairs
	val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
										~ (compareBy {it.first})
	val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
	val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
	sortBy
 */
/* hashmap
	val h = HashMap<String,Int>()
	for (i in 0..n-2) {
		val w = s.substring(i,i+2)
		val c = h.getOrElse(w){0}
		h.put(w,c+1)
	}
 */
/* basically switch, can be used as expression
	when (x) {
		0,1 -> print("x <= 1")
		2 -> print("x == 2")
		else -> { // Note the block
			print("x is neither 1 nor 2")
		}
	}
*/
// swap : a = b.also { b = a }
// arraylist remove element at index: removeAt, not remove ...
// lower bound: use .binarySearch()
//----------------------------------------------------------------------------------
//fun dfs(a: Int, b: Int) {
//    if (cur == k) return
//    ans[a] = true
//    if (b != 0) {
//        cur ++
//        deg[a] ++
//        if (deg[b] == 1) cur --
//        deg[b] ++
//        if (deg[b] == 1) cur ++
//    }
//    for (i in adj[a]) if (i != b) {
//        dfs(i,a)
//    }
//}
//  
//----------------------------------------------------------------------------------
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
// var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })  ,   
// ArrayList - ,   
// Array<Int>(n){0} - ,     
// ArrayList< ArrayList<Int> >() - 
// Array(n, { ArrayList<Pair<Int, Int>>() }) -  ,   
// var g = Array(n) { ArrayList<Int>() } -  
// val , var 
// ---------------------------------------------------
// var cnt = IntArray(MAX)
// var r = readInts()
//    for (x in r) cnt[x]++
//    3 (ok)
//val A = nextLongs()
//val a = Array<Long>(n,{0})
//for (i in 0..n-1) a[i] = A[i]
//  ArrayList  
//a.sort()
// for (x in a),  a - , 
//----------------------------------------------------
//   var
// mutableListOf<Int>() -         
//     - $x,$a
// var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)}) - quick initialize
// b.sortWith(compareBy({it.first}, {it.second})) - sort pairs
//var A: Array<Int> = TODO() , initialize global array
fun main(args: Array<String>) {
    var t=1
    t=readInt()
    while (t-->0)
    {
        var (n,k)=readInts()
        var p =readInts()
        var ans=0
        var i=n-1
        var dist=0
        var cnt=0
        var now=0
        while (i>=0)
        {
            dist++
            if (dist==k)
            {
                now+=p[i]
                dist=0
                cnt++
            }
            else
            {
                if (cnt!=0) {
                    now -= p[i + cnt]
                    now+=p[i]
                }
            }
            ans=kotlin.math.max(ans,now)
            i--
        }
        println(ans)
    }
}