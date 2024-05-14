import { _decorator, Component, Node, input, Input, EventKeyboard, KeyCode, Label, EventMouse, Vec3, Prefab, instantiate, Line, geometry } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('gameroot')
export class gameroot extends Component {
    @property(Node)heng:Node;
    @property(Node)shu:Node;
    @property(Node)player:Node;
    @property(Label)label:Label;
    @property(Node)enemy:Node;
    @property(Prefab)cheP:Prefab;
    @property(Prefab)maP:Prefab;
    @property(Prefab)paoP:Prefab;
    @property(Prefab)shuaiP:Prefab;
    @property(Prefab)shiP:Prefab;
    @property(Prefab)xiangP:Prefab;
    @property(Prefab)bingP:Prefab;

    xPos=4;xPosArr=[];
    yPos=9;yPosArr=[];
    bullet=2;
    shuai=1;shi=0;ma=0;xiang=0;che=0;pao=0;bing=1;

    start() {
    this.init();
    this.inputEvent();
    }

    init(){
        for(let i=0;i<this.heng.children.length;i++){
            const l1=this.heng.children[i].position.x;
            this.xPosArr[i]=l1;
        }
        for(let j=this.shu.children.length-1;j>=0;j--){
            const l2=this.shu.children[j].position.y;
            this.yPosArr[j]=l2;
        }
         this.renderPos();
         this.createEnemy();
    }

    createEnemy(){
        for(let i=0;i<this.shuai;i++){
             const t=instantiate(this.shuaiP);
             this.enemy.addChild(t);
             t.setPosition(this.xPosArr[4],this.yPosArr[0]);
        }
        for(let i=0;i<this.shi;i++){
            const t=instantiate(this.shiP);
            this.enemy.addChild(t);
            if(i==0) t.setPosition(this.xPosArr[3],this.yPosArr[0]);
            if(i==1) t.setPosition(this.xPosArr[5],this.yPosArr[0]);
        }
        for(let i=0;i<this.xiang;i++){
            const t=instantiate(this.xiangP);
            this.enemy.addChild(t);
            if(i==0) t.setPosition(this.xPosArr[2],this.yPosArr[0]);
            if(i==1) t.setPosition(this.xPosArr[6],this.yPosArr[0]);
        }
        for(let i=0;i<this.ma;i++){
            const t=instantiate(this.maP);
            this.enemy.addChild(t);
            if(i==0) t.setPosition(this.xPosArr[1],this.yPosArr[0]);
            if(i==1) t.setPosition(this.xPosArr[7],this.yPosArr[0]);
        }
        for(let i=0;i<this.che;i++){
            const t=instantiate(this.cheP);
            this.enemy.addChild(t);
            if(i==0) t.setPosition(this.xPosArr[0],this.yPosArr[0]);
            if(i==1) t.setPosition(this.xPosArr[8],this.yPosArr[0]);
        }
        for(let i=0;i<this.pao;i++){
            const t=instantiate(this.paoP);
            this.enemy.addChild(t);
            if(i==0) t.setPosition(this.xPosArr[1],this.yPosArr[2]);
            if(i==1) t.setPosition(this.xPosArr[7],this.yPosArr[2]);
        }
        for(let i=0;i<this.bing;i++){
            const t=instantiate(this.bingP);
            this.enemy.addChild(t);
            if(i==0) t.setPosition(this.xPosArr[4],this.yPosArr[3]);
            if(i==1) t.setPosition(this.xPosArr[2],this.yPosArr[3]);
            if(i==2) t.setPosition(this.xPosArr[6],this.yPosArr[3]);
            if(i==3) t.setPosition(this.xPosArr[0],this.yPosArr[3]);
            if(i==4) t.setPosition(this.xPosArr[8],this.yPosArr[3]);
        }
    }

    inputEvent(){
        input.on(Input.EventType.KEY_DOWN,this.keyDown,this);//检测键盘输入
        input.on(Input.EventType.MOUSE_DOWN,this.mouseDown,this);
    }

    keyDown(event:EventKeyboard){
         switch(event.keyCode){
            case KeyCode.KEY_A:
                this.movePlayer(-1,0);break;
            case KeyCode.KEY_D:
                this.movePlayer(1,0);break;
            case KeyCode.KEY_W:
                this.movePlayer(0,-1);break;
            case KeyCode.KEY_S:
                this.movePlayer(0,1);break;
         }
    }

    mouseDown(event:EventMouse){
          const x=event.getLocationX();
          const y=event.getLocationY();
          this.shoot(x,y);
    }

    shoot(x:number,y:number){
        if(this.bullet==0){this.loadBullet();return;}
        this.bullet--;
        this.showBullet();
        let start:Vec3=this.player.getWorldPosition();
        const ray=new geometry.Line(start.x,start.y,0,x,y,0);
        console.log(ray)
    }

    loadBullet(){
        if(this.bullet<2){this.bullet++;}
        this.showBullet();
    }

    showBullet(){
        this.label.string="子弹数："+this.bullet;
    }

    movePlayer(add1:number=0,add2:number=0){
         this.xPos+=add1;
         this.yPos+=add2;
         if(this.xPos<0){this.xPos=0}
         if(this.xPos>8){this.xPos=8;}
         if(this.yPos<0){this.yPos=0;}
         if(this.yPos>9){this.yPos=9;}
         this.renderPos();
         this.loadBullet();
    }

    renderPos(){
         const x=this.xPosArr[this.xPos];
         const y=this.yPosArr[this.yPos];
         console.log(x,y)
         this.player.setPosition(x,y);
    }

    update(deltaTime: number) {
        
    }
}


