<!--
 * Copyright 2001-2009 The Apache Software Foundation.
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
 */ -->

To generate the ddl, in the juddi-core module run

mvn hibernate3:hbm2ddl

This will create a target/hibernate3/sql/schema.ddl file containing the creation SQL for the
database type specified in the juddi-core/src/test/resources/META-INF/persistence.xml.

Dialects can be found at https://www.hibernate.org/hib_docs/v3/api/org/hibernate/dialect/package-summary.html

DB2Dialect
DerbyDialect
MySQLDialect
MySQL5InnoDBDialect
Oracle9Dialect
PostgreSQLDialect
SQLServerDialect
Sybase11Dialect



Since 3.2.1, these files are now no longer included in the source distribution.
Why? because we now include DDL generation in the build process