import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test01 {
    public static List<Integer> longestSubsequence(List<Integer> arr, int difference) {
        LinkedList<Integer> restul = new LinkedList<>();
        //最小返回1
        int max = 1;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0;i<arr.size();i++){
            //查看在这个数之前是否有length - difference这个数，有则返回，没有就是null
            Integer val = map.get(arr.get(i) - difference);
            if(val != null){
                // +1 左闭右开
                map.put(arr.get(i),val+1);

                //得到最大长度
                max = max >= val+1 ? max : val+1;
            }
            else
                map.put(arr.get(i),1);
        }
        int index = 1;
        for (Integer num:map.keySet()
        ) {
//            System.out.println(num +" : "+map.get(num));
            if (map.get(num)==index)
            {
                restul.add(num);
                index++;
            }
        }
//        System.out.println(max);
//        for (Integer i: arr
//             ) {
//            if (restul.get(0)- i ==difference){
//                restul.addFirst(i);
//                break;
//            }
//        }
//        System.out.println(restul);
        return restul;
    }

    public static void main(String[] args) throws IOException {
        // 读取数据
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String [] strings = bufferedReader.readLine().trim().split(" ");
        // 递增序列最大差值
        Set<Integer> div1 = new HashSet<>();
        Set<Integer> div2 = new HashSet<>();

        ArrayList<Integer> s1 = new ArrayList<>();
        for (int i = 0;i< strings.length; i++){
            Integer number = Integer.parseInt(strings[i].trim());
            s1.add(number);
            if(i!=0){
                for (int j = i;j>0 ;j--)
                {
                    div1.add(number - s1.get(j-1));
                }
            }
        }
        strings = bufferedReader.readLine().trim().split(" ");
        ArrayList<Integer> s2 = new ArrayList<>();
        for (int i = 0;i< strings.length; i++){
            Integer number = Integer.parseInt(strings[i].trim());
            s2.add(number);
            if(i!=0){
                for (int j = i;j>0 ;j--)
                {
                    div2.add(number - s2.get(j-1));
                }
            }
        }
//        System.out.println(div1);
//        System.out.println(div2);
        //交集
        Set<Integer> set = new HashSet<>();
        set.addAll(div1);
        set.retainAll(div2);
//        System.out.println(set);
        Map<Integer,List<List<Integer>>> result = new HashMap<>();
        for (Integer a: set
             ) {
            List<Integer> res1 = longestSubsequence(s1,a);
            List<Integer> res2 = longestSubsequence(s2,a);
            int min = Math.min(res1.size(),res2.size());
            List<List<Integer>> wapres = new LinkedList<>();
            wapres.add(res1.subList(0,min));
            wapres.add(res2.subList(0,min));
            result.put(min, wapres);
        }
        Integer maxkey = 0;
        for (Integer num:result.keySet()
             ) {
            maxkey = Math.max(maxkey,num);
        }
        StringBuffer stringBuffer = new StringBuffer();
        System.out.println(maxkey);
        if (maxkey == 0) return;
        for (List<Integer> list: result.get(maxkey)
             ) {
            for (Integer i:list
                 ) {
                stringBuffer.append(i+" ");
            }
            System.out.println(stringBuffer.toString().trim());
            stringBuffer = new StringBuffer();
        }
    }

}