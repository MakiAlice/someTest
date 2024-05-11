import { _decorator, Component, Node, input, Input, EventKeyboard, KeyCode, Label, EventMouse, Vec3 } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('gameroot')
export class gameroot extends Component {
    @property(Node)heng:Node;
    @property(Node)shu:Node;
    @property(Node)player:Node;
    @property(Label)label;
    @property(Node)qiPan:Node;

    xPos=4;xPosArr=[];
    yPos=9;yPosArr=[];
    bullet=2;

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
        let v1=new Vec3(x,y,0);
        let v2=new Vec3(0,0,0);
        this.qiPan.inverseTransformPoint(v2,v1);
    }

    movePlayer(add1:number=0,add2:number=0){
         this.xPos+=add1;
         this.yPos+=add2;
         if(this.xPos<0){this.xPos=0}
         if(this.xPos>8){this.xPos=8;}
         if(this.yPos<0){this.yPos=0;}
         if(this.yPos>9){this.yPos=9;}
         this.renderPos();
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


