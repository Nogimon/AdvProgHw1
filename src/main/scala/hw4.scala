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

        
        /*
        val list1 = List(("a", "b", 2),2,3)
        val list2 = List(3,("b",4))
        val list3 = list1 ::: list2
        println(list3)

        var list11 = List(("a","b"),3)
        list11 = list11 ::: List(("a","b","c"),4)
        print(list11)
        */

        var stats = List[(String, String, Any)]()

        for (list1 <- list)
        {
            //split every line of the list by ', and then pick up the three needed elements
            val splitstring = list1.split("\'")
            stats = stats ::: List((splitstring(1), splitstring(3), splitstring(4)(2)))
            //println(stats)
        }
        println("stats")
        //println(stats)
        //stats.foreach(println)


        for (stat <- stats)
        {
            println(stat._2)
            //stat._2.groupBy((word:String) => word).mapValues(_.length)
            val wordCount = stat._2.groupBy(w => w).mapValues(_.size)
            println(wordCount)
        }


    }

}
