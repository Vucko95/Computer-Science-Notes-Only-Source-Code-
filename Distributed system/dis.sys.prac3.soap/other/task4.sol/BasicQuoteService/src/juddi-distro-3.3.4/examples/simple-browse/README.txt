This example contains one class: the SimplePublish.java. When
executed it will obtain an AuthToken and use it to publish
a Publisher, a Business and a Service. 

1. Start the jUDDI-server (juddi-tomcat or juddi-bundle)

2. Check the settings of the META-INF/uddi.xml, to make sure the serverName and serverPort are set correctly.

3. mvn -Pdemo test


You should see the following output being written to the console:

    root AUTHTOKEN = authtoken:4b627696-c4b4-4343-bdae-6866e242bff3
    ===============================================
    Business Key: uddi:juddi.apache.org:businesses-asf
    Name: An Apache jUDDI Node 
    Name: This is a UDDI v3 registry node as implemented by Apache jUDDI. 
    Services:
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-custodytransfer
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: UDDI Custody and Ownership Transfer Service 
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-inquiry
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: UDDI Inquiry Service 
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-publish
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: UDDI Publish Service 
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-security
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: UDDI Security Service 
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-subscriptionlistener
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: UDDI Subscription Listener Service 
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-subscription
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: UDDI Subscription Service 
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:services-publisher
    Owning Business Key: uddi:juddi.apache.org:businesses-asf
    Name: jUDDI Publisher Service 
    ===============================================
    Business Key: uddi:juddi.apache.org:75a21da1-6a48-419b-a54e-57d696cd92f3
    Name: My Business 
    Name: 
    Services:
    -------------------------------------------
    Service Key: uddi:juddi.apache.org:82c2d59c-ceb1-4b82-8fbf-121c38fbc147
    Owning Business Key: uddi:juddi.apache.org:75a21da1-6a48-419b-a54e-57d696cd92f3
    Name: My Service 
    Business Detail - key: uddi:juddi.apache.org:businesses-asf
    Name: An Apache jUDDI Node 
    CategoryBag: Key Ref: Name= Value=node tModel=uddi:uddi.org:categorization:nodes
    
    Business Detail - key: uddi:juddi.apache.org:75a21da1-6a48-419b-a54e-57d696cd92f3
    Name: My Business 
    CategoryBag: no data
    Fetching data for business uddi:juddi.apache.org:businesses-asf
    Name UDDI Custody and Ownership Transfer Service 
    Desc Web Service supporting UDDI Custody and Ownership Transfer API 
    Key uddi:juddi.apache.org:services-custodytransfer
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-custodytransfer-ws
    Access Point: http://localhost:8080/juddiv3//services/custody-transfer?wsdl type wsdlDeployment
    Name UDDI Inquiry Service 
    Desc Web Service supporting UDDI Inquiry API 
    Key uddi:juddi.apache.org:services-inquiry
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-inquiry-ws
    Access Point: http://localhost:8080/juddiv3//services/inquiry?wsdl type wsdlDeployment
    Name UDDI Publish Service 
    Desc Web Service supporting UDDI Publish API 
    Key uddi:juddi.apache.org:services-publish
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-publish-ws
    Access Point: http://localhost:8080/juddiv3//services/publish?wsdl type wsdlDeployment
    Name UDDI Security Service 
    Desc Web Service supporting UDDI Security API 
    Key uddi:juddi.apache.org:services-security
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-security-ws
    Access Point: http://localhost:8080/juddiv3//services/security?wsdl type wsdlDeployment
    Name UDDI Subscription Listener Service 
    Desc Web Service supporting UDDI Subscription Listener API 
    Key uddi:juddi.apache.org:services-subscriptionlistener
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-subscriptionlistener-ws
    Access Point: http://localhost:8080/juddiv3//services/subscription-listener?wsdl type wsdlDeployment
    Name UDDI Subscription Service 
    Desc Web Service supporting UDDI Subscription API 
    Key uddi:juddi.apache.org:services-subscription
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-subscription-ws
    Access Point: http://localhost:8080/juddiv3//services/subscription?wsdl type wsdlDeployment
    Name jUDDI Publisher Service 
    Desc Web Service supporting jUDDI specific API 
    Key uddi:juddi.apache.org:services-publisher
    Cat bag no data
    Item is not digitally signed
    Binding Key: uddi:juddi.apache.org:servicebindings-publisher-ws
    Access Point: http://localhost:8080/juddiv3//services/publisher?wsdl type wsdlDeployment
    ................
    Fetching data for business uddi:juddi.apache.org:75a21da1-6a48-419b-a54e-57d696cd92f3
    Name My Service 
    Desc 
    Key uddi:juddi.apache.org:82c2d59c-ceb1-4b82-8fbf-121c38fbc147
    Cat bag no data
    Item is not digitally signed
    ................

However since the keys are being generated in this case your keys will differ.

