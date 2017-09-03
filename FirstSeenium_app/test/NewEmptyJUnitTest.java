/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

/**
 *
 * @author Iranga
 */
public class NewEmptyJUnitTest {
    
    public NewEmptyJUnitTest() {
    }
    static WebDriver driver;
    @BeforeClass
    public static void setUpClass() {
        System.setProperty("webdriver.chrome.driver","C:\\Users\\Iranga\\Desktop\\SeleniumWebTestingWorkshop\\Lib\\chromedriver.exe");
        driver = new ChromeDriver();
        driver.get("https://enterprise-demo.orangehrmlive.com");
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    // TODO add test methods here.
    // The methods must be annotated with annotation @Test. For example:
    //
     @Test
    // public void hello() {}
    
    public void TestA(){
            driver.findElement(By.id("txtUsername")).sendKeys("Admin");
            driver.findElement(By.xpath("//*[@id=\"txtPassword\"]")).sendKeys("admin");
            driver.findElement(By.id("btnLogin")).click();
            String expected_title = driver.getTitle();
            String actual_title = "OrangeHRM";
            Assert.assertEquals(expected_title,actual_title);
    
}
}