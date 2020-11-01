/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

package org.apache.river.examples.hello.api;

import java.io.IOException;
import java.rmi.Remote;

/**
 * This is the interface for a greeter service. 
 * Note that it extends java.rmi.Remote.  This isn't strictly necessary - 
 * we could have had a plain interface and then created a proxy that implements that
 * interface while extending Remote.  But in this case, we know it's going to be implemented
 * as a remote service, so it simplifies things if we just extend Remote.

 * Note: This code is part of a comprehensive tutorial - Be sure to have a look
 * at the 'README.md' file in the root of the parent 'river-examples' project
 * for instructions on how to build and view the complete tutorial.
 * 
 */
public interface Greeter extends Remote {
    /**
     * Say 'Hello' to the client with the name provided.
     * @param name The name of the client.
     * @return a greeting message.
     * @throws IOException 
     */
    public String sayHello(String name) throws IOException;
}
