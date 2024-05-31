import { _decorator, Component, Node, Input, EventTouch, Prefab, instantiate, Sprite, SpriteFrame, resources, ImageAsset, input, Collider2D, Contact2DType, IPhysics2DContact, spriteAssembler, Label } from 'cc';
const { ccclass, property } = _decorator;
@ccclass('tower')
export class tower extends Component {
    @property(Node) circle: Node;
    @property(Prefab) tower1: Prefab;
    @property(Prefab) tower2: Prefab;
    @property(Prefab) delete:Prefab;
    @property(Node) tower: Node;
    @property(Node) battleField: Node;
    @property(Node)enemys:Node;
    @property(Node)coin:Node;
    touchtime: number = 0;
    istowerbuild = 0;
    Coin=100;
    pre=new Node;
    image;
    start() {
        this.battleField.active = false;
        this.circle.on(Input.EventType.TOUCH_END, this.onTouch, this);
        this.circle.on(Input.EventType.TOUCH_END, this.afterTowerBuild, this);
        this.schedule(this.openCollider, 1);
        this.pre.addComponent(Sprite);
        this.pre.getComponent(Sprite).fillRange=0;
        this.image=this.circle.getComponent(Sprite).spriteFrame;
        this.schedule(()=>{this.Coin=parseInt(this.coin.getComponent(Label).string);this.coinShow()},1);
        //从coin里读取string来维护一个公共的coin
    }

    coinShow(){
        this.coin.getComponent(Label).string=this.Coin.toString();
    }

    onTouch(event: EventTouch) {
        //点击塔基事件，如果已建造塔设置touchtime为-1，不再触发
        if (this.touchtime == 0) {
            const l1 = instantiate(this.tower1);
            const l2 = instantiate(this.tower2);
            const po = this.circle.getPosition();
            po.y += 60; po.x -= 50;
            l1.setPosition(po);
            this.tower.addChild(l1);
            this.tower.children[0].on(Input.EventType.TOUCH_END, this.towerChoose, this);
            po.x += 100;
            l2.setPosition(po);
            this.tower.addChild(l2);
            this.tower.children[1].on(Input.EventType.TOUCH_END, this.towerChoose, this);
            this.touchtime = 1;
        }
        else if (this.touchtime == 1) {
            for (let i = 0; i < this.tower.children.length; i++) {
                this.tower.children[i].destroy();
            }
            this.touchtime = 0;
        }
    }

    towerChoose(event) {
        //建塔事件，将塔基的精灵帧替换为塔，同时减少金币
        const l1 = event.target._name;
        let temp = '';//动态选择塔
        if (l1 == 'tower1p' && this.Coin>=50) { temp = 'tower1/spriteFrame'; this.istowerbuild = 1;this.Coin-=50;}
        if (l1 == 'tower2p' && this.Coin>=75) { temp = 'tower2/spriteFrame'; this.istowerbuild = 2;this.Coin-=75;}
        if(this.istowerbuild!=0 && this.Coin>=0){
            this.touchtime = -1;
            resources.load(temp, SpriteFrame, (err, spriteFrame) => {
                this.circle.getComponent(Sprite).spriteFrame = spriteFrame;
            })
        }
        for (let i = 0; i < this.tower.children.length; i++) {
            this.tower.children[i].destroy();
        }
        this.coinShow();
    }

    afterTowerBuild() {
        //显示塔的攻击范围和删除塔返还金币
        if (this.istowerbuild != 0) {
            this.battleField.active = true;
            const l=instantiate(this.delete);
            const po=this.circle.getPosition();
            po.y-=60;
            l.setPosition(po);
            this.tower.addChild(l);
            l.on(Input.EventType.TOUCH_END,()=>{
                this.touchtime=0;
                if(this.istowerbuild==1){this.Coin+=25;}
                else if(this.istowerbuild==2){this.Coin+=35;}
                this.coinShow();
                this.istowerbuild=0;
                this.battleField.active = false;
                this.circle.getComponent(Sprite).spriteFrame=this.image;
                l.destroy();
            },this);
            input.on(Input.EventType.TOUCH_END, () => {
                this.battleField.active = false;
                if(l.isValid==true){l.destroy();}
            }, this);
        }
    }

    openCollider() {
        if (this.istowerbuild == 1) {
            const box = this.circle.getComponent(Collider2D);
            box.once(Contact2DType.PRE_SOLVE, this.battle1, this);
        }
        else if(this.istowerbuild == 2) {
            const box = this.circle.getComponent(Collider2D);
            box.once(Contact2DType.PRE_SOLVE, this.battle2, this);
        }
    }

    battle1(selfCollider: Collider2D, otherCollider: Collider2D, contact: IPhysics2DContact | null) {
        if(this.pre.isValid==false || this.pre.getComponent(Sprite).fillRange<=0){
            if(otherCollider.node.isValid==true){
            this.pre=otherCollider.node.children[0].children[0];
            this.pre.getComponent(Sprite).fillRange -= 0.1;
            }
        }
        else{
            this.pre.getComponent(Sprite).fillRange-=0.1;
        }
    }

    battle2(selfCollider: Collider2D, otherCollider: Collider2D, contact: IPhysics2DContact | null) {
        if(this.pre.isValid==false || this.pre.getComponent(Sprite).fillRange<=0){
            if(otherCollider.node.isValid==true){
            this.pre=otherCollider.node.children[0].children[0];
            this.pre.getComponent(Sprite).fillRange -= 0.15;
            }
        }
        else{
            this.pre.getComponent(Sprite).fillRange-=0.15;
        }
    }

    update(deltaTime: number) {
    }
}


