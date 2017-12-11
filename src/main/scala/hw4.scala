//hw4
import scala.io.Source

object Hw4{

    def main(args: Array[String]): Unit = {

        println("hello")
        val list = Source.fromFile("top40.sql").getLines().toList

        println(list.head)
        val splitstring = list.head.split("\'")
        splitstring.foreach(println)
        //println(splitstring(9))
        val tuple1 = (splitstring(1), splitstring(3), splitstring(4)(2))
        println(tuple1)
        //println(splitstring.head)
        println(list.tail.head)
    }

}
