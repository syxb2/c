# README.md

#### All the c codes in Bai‘s Mac

## directory:

> update: 2024/6/30/11:00

```shell
$ tree -I "*.dSYM|*.out"

.
├── README.md
├── cource
│   ├── programAlgorithms1
│   │   ├── If.c
│   │   ├── PrintfAndScanf.c
│   │   ├── StackLearning.c
│   │   ├── anytoten.c
│   │   ├── bubble.c
│   │   ├── c.c
│   │   ├── char.c
│   │   ├── download
│   │   │   ├── 231025指针
│   │   │   │   ├── find1.c
│   │   │   │   ├── find2.c
│   │   │   │   ├── p-arr2d.c
│   │   │   │   ├── reverse-array.c
│   │   │   │   └── sort.c
│   │   │   ├── 231030函数
│   │   │   │   ├── const-pointer.c
│   │   │   │   ├── decompose.c
│   │   │   │   ├── swap-by-pointer.c
│   │   │   │   └── swap-by-val.c
│   │   │   ├── 231115结构
│   │   │   │   ├── planets1.c
│   │   │   │   ├── planets2.c
│   │   │   │   └── planets3.c
│   │   │   ├── 231120栈
│   │   │   │   └── stack
│   │   │   │       ├── Makefile
│   │   │   │       ├── elem-type.h
│   │   │   │       ├── main.c
│   │   │   │       ├── stack.c
│   │   │   │       └── stack.h
│   │   │   ├── 231120链表
│   │   │   │   └── linkedlist
│   │   │   │       ├── Makefile
│   │   │   │       ├── elem-type.h
│   │   │   │       ├── list
│   │   │   │       ├── list-test.c
│   │   │   │       ├── list.c
│   │   │   │       └── list.h
│   │   │   └── 23116字符串
│   │   │       └── string.c
│   │   ├── enum.c
│   │   ├── extern
│   │   │   ├── f.c
│   │   │   ├── f.h
│   │   │   ├── main.c
│   │   │   └── note.c
│   │   ├── project
│   │   │   ├── data.txt
│   │   │   ├── file.c
│   │   │   └── rev-data.txt
│   │   ├── tentoany.c
│   │   ├── union.c
│   │   └── unsigned.c
│   └── programAlgorithms2
│       └── greatestCommonDivisor_recursion.c
├── practice
│   ├── ICPC
│   │   ├── 0vs1.c
│   │   ├── CyclicSequences.cpp
│   │   ├── NNoWhispering.c
│   │   ├── NoWhispering.c
│   │   ├── RandomSequenceDetection.c
│   │   ├── StatusMonitoring.c
│   │   ├── StatusMonitoring1.c
│   │   └── StatusMonitoring2.c
│   ├── iCoding
│   │   ├── semester1
│   │   │   ├── experience1
│   │   │   │   ├── CalculateBill.c
│   │   │   │   ├── CalculateTax.c
│   │   │   │   ├── DateFormatConvention.c
│   │   │   │   ├── FractionAddition.c
│   │   │   │   └── LoanBalance.c
│   │   │   ├── experience2
│   │   │   │   ├── 24-hourTo12-hour.c
│   │   │   │   ├── Brokerage.c
│   │   │   │   ├── CalendarMonth.c
│   │   │   │   ├── Centesimal-gradetoLetter-grade.c
│   │   │   │   ├── GreatestCommonDivisor.c
│   │   │   │   ├── SquareofEvenNumber.c
│   │   │   │   ├── UniversalProductionCode.c
│   │   │   │   └── WindSpeed.c
│   │   │   ├── experience3
│   │   │   │   ├── Encryption.c
│   │   │   │   ├── ExpressionEvaluation.c
│   │   │   │   ├── NumberOccurrences.c
│   │   │   │   ├── RandomWalk.c
│   │   │   │   ├── Translation.c
│   │   │   │   └── exp.c
│   │   │   ├── experience4
│   │   │   │   ├── Reversal.c
│   │   │   │   ├── Stack.c
│   │   │   │   └── TheBiggestandSmallestWords.c
│   │   │   ├── experience5
│   │   │   │   ├── inventory.c
│   │   │   │   ├── inventory_TODO.c
│   │   │   │   └── inventory_note.c
│   │   │   └── experience6
│   │   │       ├── app_note.c
│   │   │       ├── app_test.c
│   │   │       ├── goodsinfo copy.txt
│   │   │       ├── goodsinfo.txt
│   │   │       └── lab52.h
│   │   └── semester2
│   │       ├── 1-queueAndStack
│   │       │   ├── queue_cirLkListRepreQueue.c
│   │       │   └── stack_suffixExpressionEval.c
│   │       ├── 2-linearList
│   │       │   ├── lnkDelX2y.c
│   │       │   ├── lnkList.h
│   │       │   ├── lnkMerge.c
│   │       │   ├── lnkSearch.c
│   │       │   ├── seqDelDupnum.c
│   │       │   ├── seqDelX2y.c
│   │       │   ├── seqList.h
│   │       │   └── seqOddEven.c
│   │       ├── 3-bitree
│   │       │   ├── bitree.h
│   │       │   ├── nearest_ancestor.c
│   │       │   ├── path.c
│   │       │   ├── path_answer.c
│   │       │   ├── pre_order.c
│   │       │   ├── transform.c
│   │       │   └── transform_answer.c
│   │       ├── 4-arrayTables
│   │       │   ├── add_matrix.c
│   │       │   ├── add_matrix_answer.c
│   │       │   ├── cross_list.c
│   │       │   ├── cross_list_answer.c
│   │       │   ├── crosslist.h
│   │       │   └── tsmatrix.h
│   │       ├── 5-string
│   │       │   ├── blstrSubstr.c
│   │       │   ├── blstrSubstr_answer.c
│   │       │   ├── dsstring.h
│   │       │   ├── strCompare.c
│   │       │   └── strReplace.c
│   │       ├── 6-search
│   │       │   ├── avl.h
│   │       │   ├── avlInsert.c
│   │       │   ├── avlInsert_answer.c
│   │       │   ├── createHash.c
│   │       │   ├── hash.h
│   │       │   └── hashAdd.c
│   │       └── 7-graph
│   │           ├── adjacencyMatrix.c
│   │           ├── adjacencyTable.c
│   │           ├── adjacencyTable_answer.c
│   │           └── graph.h
│   ├── leetcode
│   │   ├── arraySign.c
│   │   ├── calPoints.c
│   │   ├── canMakeArithmeticProgression.c
│   │   ├── findTheDifference.c
│   │   ├── isAnagram.c
│   │   ├── isMonotonic.c
│   │   ├── mergeAlternately.c
│   │   ├── moveZeroes.c
│   │   └── strStr.c
│   ├── lutece
│   │   ├── Arrange.c
│   │   ├── BiliBiliACFunAndMore.c
│   │   ├── DayOfYear.c
│   │   ├── DivingScoring.c
│   │   ├── EightBall.c
│   │   ├── IsDivisibleBy3.c
│   │   ├── MedianNumber.c
│   │   ├── MonkeyChooseKing.c
│   │   ├── RotateMatrix.c
│   │   └── TurnOnLights.c
│   └── mine
│       ├── AchievementStatistics.c
│       ├── CharToInt.c
│       ├── Count2kOutLoop.c
│       ├── Hanoi.c
│       ├── HundredChickens.c
│       ├── HundredChickens.md
│       ├── InReverseOrder.c
│       ├── InReverseOrder.md
│       ├── JieCheng.c
│       ├── JieCheng2.c
│       ├── STriangle.c
│       ├── VCircle.c
│       ├── WXT.c
│       ├── a.c
│       ├── chaperII11.c
│       ├── chapterII6.c
│       ├── cmdline.c
│       ├── cosx.c
│       ├── decompose.c
│       ├── exppRepoter.c
│       ├── fact.c
│       ├── fibonacci.c
│       ├── fibonacci_1.c
│       ├── function.c
│       ├── happyNY.c
│       ├── max.c
│       ├── other.c
│       ├── palindrome.c
│       ├── planet.c
│       ├── planet2.c
│       ├── pointer.c
│       ├── practice1.c
│       ├── printf.c
│       ├── scanf.c
│       ├── test.c
│       ├── test2.c
│       ├── test4-hioi.c
│       └── yhTriangle.c
├── project_gobang
│   ├── README.md
│   ├── game.h
│   └── main.c
└── zzz_class
    ├── FileOperation.c
    ├── FileOperation.h
    ├── Makefile
    ├── README.docx
    ├── README.md
    ├── iCoding
    │   ├── 12-digitIntegerCode.c
    │   ├── GraphDominance.c
    │   └── isThereRing.c
    ├── main
    ├── main.c
    ├── package.zip
    ├── test.txt
    ├── 截屏2024-06-10 下午10.26.28.png
    └── 综合性题目（卓中卓2024）.pdf

39 directories, 194 files
```
