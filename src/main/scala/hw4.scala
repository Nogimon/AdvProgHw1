//hw4
import scala.io.Source

object Hw4{

    def main(args: Array[String]): Unit = {

        println("CSE 411: Homework4")
        println("Lian Duan\nemail: lid315@lehigh.edu\nInstructor: Prof.Femister\n")
        val list = Source.fromFile("top40.sql").getLines().toList

        var stats = List[(String, String, Any)]()

        var wordCount = Map.empty[String, Int]

        var artistCount = Map.empty[String, Int]

        var artistTopCount = Map.empty[String, Int]

        //count the times a title contains certain word
        var pCount = 0
        
        //count the times a title contains certain word and the song is a Top 1 song
        var pOneCount = 0
        
        //count the times a title is a Top 1 song
        var oneCount = 0

        for (list1 <- list)
        {
            //split everyline and write into a List with triples
            val splitString = list1.split("\'")
            stats = stats ::: List((splitString(1), splitString(3), splitString(4)(2)))

            
            val splits = splitString(3).split("\\W+")
            //Count the times the songs contain a certain word
            if (splits.contains("ME")){
                pCount += 1
                if (splitString(4)(2) == "1"(0)){
                    pOneCount += 1
                }
            }
            //Count the words in the title of the songs
            val wordCount1 = splits.foldLeft(Map.empty[String, Int]){
                (count, word) => count + (word -> (count.getOrElse(word, 0) + 1))
            }
            
            wordCount = wordCount ++ wordCount1.map{
                case(name, count) => name -> (count + wordCount.getOrElse(name,0))
            }


            //Count the names of the artist that are in Top40
            val artistCount1 = Array(splitString(1)).foldLeft(Map.empty[String, Int]){
                (count, word) => count + (word -> (count.getOrElse(word, 0) + 1))
            }

            artistCount = artistCount ++ artistCount1.map{
                case(name, count) => name -> (count + artistCount.getOrElse(name, 0))
            }

            //Count the names of the artist that are only top 1
            if(splitString(4)(2) == "1"(0)){
                val artistTopCount1 = Array(splitString(1)).foldLeft(Map.empty[String, Int]){
                    (count, word) => count + (word -> (count.getOrElse(word, 0) + 1))
                }

                artistTopCount = artistTopCount ++ artistTopCount1.map{
                    case(name, count) => name -> (count + artistTopCount.getOrElse(name, 0))
                }

                oneCount += 1
            }         
        }

        //The triples are saved in the List called "stats"
        //uncomment next line to print the stats out
        //println(stats)

        //Delete the trivial words in wordCount
        wordCount -= ("THE", "TO", "A", "AND", "", "IN", "OF", "ON", "S", "LL", "T")

        //Sort the counting result
        val wordCountSort = wordCount.toSeq.sortWith(_._2 > _._2).slice(0, 5)
        val artistCountSort = artistCount.toSeq.sortWith(_._2 > _._2).slice(0, 5)
        val artistTopCountSort = artistTopCount.toSeq.sortWith(_._2 > _._2).slice(0, 5)


        //Print out the results
        println("The most frequent non trivial words:")
        println(wordCountSort)
        println("The artists with most top 40 songs:")
        println(artistCountSort)
        println("The artists with most top 1 songs:")
        println(artistTopCountSort)
        
        println("\nP(a song being number one | the title contains \"ME\")")
        println((pOneCount:Float)/pCount)
        println("P(the title contains \"ME\" | a song being number one)")
        println((pOneCount:Float)/oneCount)
        println("In addition, the times that a title: (contains \"ME\", contains \"ME\" and won number one, won number one) is")
        println(pCount, pOneCount, oneCount)

    }

}
