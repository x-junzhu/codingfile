package edu.fzu.pen;

import java.util.Arrays;

/**
 * @author johnrambo
 * @create 2020-07-31 21:44
 */
public class Parameter {

    /*4.方法的参数传递机制
    实参给形参赋值
    基本数据类型: 数据值
    引用数据类型: 地址值
    另外: String和包装类是不可变的
     */
    
    public static void main(String[] args) {
        int i = 1;
        String str = "hello";
        Integer num = 2;
        int[] arr = {1, 2, 3, 4, 5};
        MyData my = new MyData();
        change(i, str, num, arr, my);
        System.out.println("i=" + i);//1
        System.out.println("str=" + str);//hello
        System.out.println("num=" + num);//2
        System.out.println("arr=" + Arrays.toString(arr));//[2, 2, 3, 4, 5]
        System.out.println("my.a=" + my.a);//11
    }

    public static void change(int j, String s, Integer n, int[] a, MyData m)
    {
        j += 1;
        s += "world";
        n += 1;
        a[0] += 1;
        m.a += 1;
    }
}

class MyData{
    int a = 10;
}
