/*
 * Copyright 2001-2013 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package org.apache.juddi.samples;

import java.util.concurrent.atomic.AtomicReference;
import javax.xml.ws.Holder;

/**
 * A simple program to illistrate how to pass by "reference" vs by "value" in
 * Java. Or more accurately, how to persist changes on method parameters to the
 * caller. Written mostly because I forget it frequently and use this as
 * reference material.
 *
 * @author <a href="mailto:alexoree@apache.org">Alex O'Ree</a>
 */
public class testStrings {

    public static void main(String[] args) {
        String str = "hi";
        System.out.println(str);                                                //hi
        System.out.println(Test1(str));                                         //hir
        System.out.println(Test2(str));                                         //hix
        Test3(str);
        System.out.println(str);                                                //hi no change
        Holder<String> holder = new Holder<String>();
        holder.value = str;
        Test4(holder);
        System.out.println(str);                                                //hi no change
        System.out.println(holder.value);                                       //hiw changed persists

        AtomicReference<String> astr = new AtomicReference<String>();
        astr.set(str);
        Test5(astr);
        System.out.println(str);                                                //hi no change
        System.out.println(astr.get());                                         //hit change persists

    }

    static String Test1(String s) {
        return s + "r";
    }

    static String Test2(String s) {
        s += "x";
        return s;
    }

    static void Test3(String s) {
        s += "z";
    }

    static void Test4(Holder<String> s) {
        s.value += "w";
    }

    static void Test5(AtomicReference<String> s) {
        s.set(s.get() + "t");
    }
}
