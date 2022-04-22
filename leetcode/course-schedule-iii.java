
class Solution {
    static class CompareByDeadline implements Comparator<int[]>{

    public int compare(int[] a, int[] b)
    {
        if(a[1]>b[1])return 1;
        return -1;
    }
    
}   
    static class CompareByDuration implements Comparator<int[]>{

    public int compare(int[] a, int[] b)
    {
        if(a[0]<b[0])return 1;
        return -1;
    }
    
}
    public int scheduleCourse(int[][] courses) {
//         for(int[] e: courses)
//         {
//             System.out.print(e[0]);
//             System.out.print(" ");
//             System.out.print(e[1]);
            
//             System.out.println();
//         }
//         System.out.println();
        Arrays.sort(courses, (a,b)->a[1]-b[1]);
//         for(int[] e: courses)
//         {
//             System.out.print(e[0]);
//             System.out.print(" ");
//             System.out.print(e[1]);
            
//             System.out.println();
//         }
//         System.out.println();
//         return 1;
        PriorityQueue<int[]> pq = new PriorityQueue<>(new CompareByDuration());
        int currentTime = 0;
        int numcourses = 0;
        for(int[] e : courses)
        {
            
            if(currentTime + e[0] <= e[1])
            {
                pq.add(e);
                currentTime += e[0];
                numcourses++;
            }
            else if(pq.size()>0 && pq.peek()[0] > e[0])
            {
                currentTime = currentTime - pq.poll()[0] + e[0];
                pq.add(e);
            }
        }
        return numcourses;
    }
}