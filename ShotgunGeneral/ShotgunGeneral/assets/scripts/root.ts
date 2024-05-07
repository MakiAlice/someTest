import { _decorator, Component, Node, input, Button, Input, EventTouch, director, Label, size, Size, RichText } from 'cc';
const { ccclass, property } = _decorator;

@ccclass('root')
export class root extends Component {
    @property(Node)begin:Node;
    @property(Label)dialog;
    @property(Node)Dia;
    start() {
    this.begin.on(Node.EventType.TOUCH_START,(event:EventTouch)=>{
        this.begin.setScale(0.9,0.9);
    },this);

    this.begin.on(Node.EventType.TOUCH_END,(event:EventTouch)=>{
        this.begin.setScale(1,1);
        this.begin.destroy();
        this.startDialog();
    },this);
    }

    startDialog(){
        this.dialog.string="      很久很久以前，存在着红与黑两个象棋王国。黑王暴虐无道，他的子民渐渐弃他而去...";
        this.Dia.on(Node.EventType.TOUCH_END,(event:EventTouch)=>{
            this.dialog.string="      然而，恼羞成怒的黑王不思悔改，拿出了王国代代相传的武器：霰弹枪，来夺回他失去的一切...";
            this.Dia.on(Node.EventType.TOUCH_END,(event:EventTouch)=>{
                this.dialog.destroy();
                this.changeScene();
            },this)
        },this)
    }

    changeScene(){
        director.loadScene("playground");
    }


    update(deltaTime: number) {
        
    }
}


