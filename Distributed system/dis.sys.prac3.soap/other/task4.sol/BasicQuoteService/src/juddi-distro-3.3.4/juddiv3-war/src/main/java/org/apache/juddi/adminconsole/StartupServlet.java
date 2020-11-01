/*
 * Copyright 2001-2008 The Apache Software Foundation.
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
package org.apache.juddi.adminconsole;

import org.apache.juddi.config.PersistenceManager;

import javax.servlet.ServletContextEvent;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * This startup servlet's job is to generate an encryption key which will be
 * used for encrypting cached user credentials in the http session object
 *
 * @author <a href="mailto:alexoree@apache.org">Alex O'Ree</a>
 */
public class StartupServlet implements javax.servlet.ServletContextListener {

    static final Logger log = Logger.getLogger(StartupServlet.class.getCanonicalName());

    /**
     * creates a new AES key and stores it to the properties files
     *
     * @param sce
     */
    @Override
    public void contextInitialized(ServletContextEvent sce) {
        log.info("juddi-admin gui startup");
        FileOutputStream fos = null;
        try {
            Properties p = new Properties();
            String key = generateKey();
            if (key == null) return;
            p.put("key", key);
            fos = new FileOutputStream(sce.getServletContext().getRealPath("/WEB-INF/config.properties"));
            log.log(Level.INFO, "Storing key to " + sce.getServletContext().getRealPath("/WEB-INF/config.properties"));
            p.store(fos, "No comments");
            fos.flush();
            fos.close();
        } catch (Exception ex) {
            log.log(Level.WARNING, null, ex);
            try {
                if (fos != null) {
                    fos.close();
                }
            } catch (Exception e) {
            }
        }
    }

    private String generateKey() {
        String key = generateKey(256);
        if (key == null) {
            key = generateKey(128);
        }
        if (key == null) {
            log.severe("128 bit key validation failed! giving up, user's won't be able to login! ");
            return null;
        }
        return key;
    }

    private String generateKey(int length) {
        log.info("Attempting to generate " + length + " bit AES key");
        String key = AES.GEN(length);
        if (key != null) {
            if (AES.ValidateKey(key)) {
                log.info("Generation of " + length + " bit AES key successful");
            } else {
                log.warning(length + " bit key validation failed. To use higher key sizes, try installing the Java Cryptographic Extensions (JCE) Unlimited Strength");
                return null;
            }
        }
        return key;
    }

    /**
     * @param sce
     */
    @Override
    public void contextDestroyed(ServletContextEvent sce) {
        removeKeyFromConfigurationFile(sce);
        PersistenceManager.closeEntityManager();
    }

    private void removeKeyFromConfigurationFile(ServletContextEvent sce) {
        FileOutputStream fos = null;
        try {
            log.info("Cleaning up juddi-admin");
            Properties p = new Properties();
            InputStream is = sce.getServletContext().getResourceAsStream("/WEB-INF/config.properties");
            p.load(is);
            p.remove("key");
            is.close();
            fos = new FileOutputStream(sce.getServletContext().getRealPath("/WEB-INF/config.properties"));
            p.store(fos, "No comments");
            fos.flush();
            fos.close();
        } catch (Exception ex) {
            log.log(Level.WARNING, null, ex);
            try {
                if (fos != null) {
                    fos.close();
                }
            } catch (Exception e) {
            }
        }
        try {
            sce.getServletContext().removeAttribute("username");
            sce.getServletContext().removeAttribute("password");
            sce.getServletContext().removeAttribute("locale");
            sce.getServletContext().removeAttribute("hub");
        } catch (Exception ex) {
            log.log(Level.WARNING, null, ex);
        }
    }
}
