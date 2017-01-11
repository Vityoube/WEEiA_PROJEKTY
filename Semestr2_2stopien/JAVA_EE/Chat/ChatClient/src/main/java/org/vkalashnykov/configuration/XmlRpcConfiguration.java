package org.vkalashnykov.configuration;

import org.apache.xmlrpc.client.XmlRpcClient;
import org.apache.xmlrpc.client.XmlRpcClientConfigImpl;

import java.net.MalformedURLException;
import java.net.URL;

/**
 * Created by vkalashnykov on 28.12.16.
 */
public class XmlRpcConfiguration {
    private static final String serverUrl="http://localhost:8090/xmlrpc";

    private static final XmlRpcClient xmlRpcClient=new XmlRpcClient();

    public static void configureXmlRpcClient(){
        final XmlRpcClientConfigImpl config=new XmlRpcClientConfigImpl();
        try {
            System.out.println("Trying connect to server "+serverUrl);
            config.setServerURL(new URL(serverUrl));
        } catch (MalformedURLException e) {
            System.err.println("Server "+serverUrl+" not found.");
            e.printStackTrace();
        }
        xmlRpcClient.setConfig(config);
        System.out.println("Connected to server: "+serverUrl);
    }

    public static XmlRpcClient getXmlRpcServer(){
        return xmlRpcClient;
    }
}
