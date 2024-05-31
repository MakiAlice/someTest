import { _decorator, Component, Node, Collider2D, Contact2DType, IPhysics2DContact, Prefab, instantiate, Input, Sprite, director, macro, ResolutionPolicy, view } from 'cc';
import { data } from './data';
const { ccclass, property } = _decorator;
@ccclass('goal')
export class goal extends Component {
    @property(Node)goal:Node;
    @property(Node)hearts:Node;
    @property(Node)button:Node;
    @property(Node)result:Node;
    @property(Node)enemys:Node;
    @property(Node)button2:Node;
    life=3;
    start() {
        for(let i=0;i<this.result.children.length;i++){
            this.result.children[i].active=false;
        }
        this.schedule(this.openCollider, 1);
        this.schedule(this.checkResult,1,macro.REPEAT_FOREVER,5);
        this.button.on(Input.EventType.TOUCH_END,()=>{this.lifeMinus();},this);
        this.button2.on(Input.EventType.TOUCH_END,()=>{
            var root=director.getScene().getChildByName("data");
            root.getComponent(data).setData(0,1);
            director.pause();
            this.result.children[0].active=true;
            this.result.children[0].children[0].on(Input.EventType.TOUCH_END,this.replay,this);
            this.result.children[0].children[1].on(Input.EventType.TOUCH_END,this.back,this)
        },this);
        view.setDesignResolutionSize(1280,720,ResolutionPolicy.EXACT_FIT);
    }

    openCollider(){
        const box = this.goal.getComponent(Collider2D);
        box.once(Contact2DType.PRE_SOLVE, this.touchGoal, this);
    }

    touchGoal(selfCollider: Collider2D, otherCollider: Collider2D, contact: IPhysics2DContact | null){
        this.lifeMinus();
        if(otherCollider.node.isValid==true){
            otherCollider.node.children[0].children[0].getComponent(Sprite).fillRange=0;
        }
    }

    lifeMinus(){
        this.life-=1;
        this.hearts.children[this.life].destroy();
        if(this.life<=0){
            director.pause();
            this.result.children[1].active=true;
            this.result.children[1].children[0].on(Input.EventType.TOUCH_END,this.replay,this);
            this.result.children[1].children[1].on(Input.EventType.TOUCH_END,this.back,this)
        }
    }

    checkResult(){
        if(this.enemys.children.length==0){
            var root=director.getScene().getChildByName("data");
            root.getComponent(data).setData(0,1);
            director.pause();
            this.result.children[0].active=true;
            this.result.children[0].children[0].on(Input.EventType.TOUCH_END,this.replay,this);
            this.result.children[0].children[1].on(Input.EventType.TOUCH_END,this.back,this)
        }
    }

    replay(){
        director.loadScene('stage1');
        director.resume();
    }

    back(){
        director.loadScene('stage')
        director.resume();
    }

    update(deltaTime: number) {
    }
}


