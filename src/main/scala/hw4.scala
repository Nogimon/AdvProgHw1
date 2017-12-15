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

        var wordcount = Map("the" -> 2)

        for (list1 <- list)
        {
            //split every line of the list by ', and then pick up the three needed elements
            val splitstring = list1.split("\'")
            stats = stats ::: List((splitstring(1), splitstring(3), splitstring(4)(2)))
            //println(stats)

            val wordcount1 = splitstring(3).split("\\W+").foldLeft(Map.empty[String, Int]){
                (count, word) => count + (word -> (count.getOrElse(word, 0) + 1))
            }
            
            wordcount = wordcount ++ wordcount1.map{case(name, count) => name->(count + wordcount.getOrElse(name,0))}

            /*
            val merge = wordcount.toSeq ++ wordcount1.toSeq
            val grouped = merge.groupBy(_._1)
            wordcount = grouped.mapValues(_.map(_._2).toList)
            */
            


        }
        println("stats")

        val wordcountsort = wordcount.toSeq.sortBy(_._2)

        println(wordcountsort)
        
        //println(stats)
        //stats.foreach(println)
        
        /*
        for (stat <- stats)
        {
            println(stat._2)
            //stat._2.groupBy((word:String) => word).mapValues(_.length)
            //val wordcount = stat._2.groupBy(w => w.split(" ")).mapValues(_.size)
            
            val wordcount = stat._2.foldLeft(Map.empty[String, Int]){
                (count, word) => count + (word -> (count.getOrElse(word, 0) + 1))
            }
            
            println(wordcount)
        }
        */


    }

}
