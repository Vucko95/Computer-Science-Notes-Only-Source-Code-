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
package org.apache.river.examples.browser;

import java.security.Policy;
import java.util.logging.Level;
import java.util.logging.Logger;
import net.jini.security.policy.DynamicPolicyProvider;
import net.jini.security.policy.PolicyInitializationException;

/**
 *
 * This is a quick class to print out the security manager and policy provider,
 * primarily to verify whether a command line invocation is working correctly.
 */
public class ShowSecuritySetup {

    public static void main(String[] args) {
        SecurityManager securityManager = System.getSecurityManager();
        if (securityManager == null) {
            System.out.println("No security manager installed.");
            return;
        }
        System.out.println("Security Manager is " + System.getSecurityManager().getClass().getName());
        Policy policy = Policy.getPolicy();
        System.out.println("Policy is " + policy.getClass().getName());
        try {
            Class dynPolicyClass = Class.forName("net.jini.security.policy.DynamicPolicyProvider");
            System.out.println("Loaded policy provider class " + dynPolicyClass.getName());
        } catch (ClassNotFoundException ex) {
            System.out.println("Couldn't find DynamicPolicyProvider.");
        }
        try {
            System.out.println("Attempting to set the policy...");
            policy = new DynamicPolicyProvider();
            Policy.setPolicy(policy);
            policy = Policy.getPolicy();
            System.out.println("Policy is " + policy.getClass().getName());
        } catch (PolicyInitializationException ex) {
            Logger.getLogger(ShowSecuritySetup.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}
