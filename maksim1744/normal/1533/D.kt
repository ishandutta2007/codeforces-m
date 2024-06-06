/*
    author:  Maksim1744
    created: 29.06.2021 17:45:29
*/

fun main() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
    var cnt = HashSet<String>()
    repeat(n) {
        var s = readLine()!!
        cnt.add(s)
    }

    var q = readLine()!!.toInt()
    repeat(q) {
        var t = readLine()!!
        var ans = 0
        for (i in 0 until m + 1) {
            if (i == 0 || t[i] != t[i - 1]) {
                var cur = t.substring(0, i) + t.substring(i + 1, m + 1);
                if (cnt.contains(cur)) {
                    ans += 1
                }
            }
        }
        println(ans)
    }
}

/*

read array: readLine()!!.split(' ').map{ it.toInt() }.toMutableList()

var mp = HashMap<Int, Int>();
mp.getValue(k)
if (mp.contains(k))
mp.put(a, b)

val s = StringBuilder("test");
s[0] = 'g';
s.append(s);
println(s); // gestgest



credits: aleks5d

    
   )))

:
kotlinc A.kt -include-runtime -d A.jar
java -jar A.jar

  :
Pair<T1, T2> - 
Pair(a, b) -  
     - 

  (  ?)     
    !

    , ?
 : arr.sort()
  /    
arr.sortWith(compareBy({it.first}, {it.second}))  arr.sortWith(compareBy({it[0]}, {it[1]}))   

   
  ArrayList
ArrayList<Int>()
push_back = add
pop_back = removeAt(lastIndex)
arrayListOf()
list.binarySearch()

HashMap<String,Int>()

PriorityQueue<Pair<Long,Int>>({x,y ->
    x.first.compareTo(y.first)})

var A = arrayListOf(Pair(1,3),Pair(2,2),Pair(3,1))
val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
    x.second.compareTo(y.second)})

             )))
*/