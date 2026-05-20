/* ===== 23e88f040 workers.fishing.store_fish:? ===== */
/* ghidra_name=FUN_23e88f040 entry=23e88f040 size=11784 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_23e88f040(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  code *pcVar9;
  code *pcVar10;
  undefined1 auVar11 [16];
  longlong *plVar12;
  char cVar13;
  int iVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong *plVar22;
  undefined8 *puVar23;
  undefined4 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  undefined1 auStack_98 [16];
  longlong *plStack_88;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar15 = _DAT_23eede640;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[3];
  plVar3 = (longlong *)param_3[1];
  plStack_88 = (longlong *)0x0;
  plVar4 = (longlong *)param_3[2];
  auStack_98 = (undefined1  [16])0x0;
  if (_DAT_23eede640 == (longlong *)0x0) {
LAB_23e88f0c1:
    _DAT_23eede640 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede638,DAT_23eede708,0x80);
  }
  else {
    lVar17 = *_DAT_23eede640;
    if (1 < lVar17) {
      *_DAT_23eede640 = lVar17 + -1;
      goto LAB_23e88f0c1;
    }
    if (_DAT_23eede640[2] != 0) {
      *_DAT_23eede640 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      goto LAB_23e88f0c1;
    }
  }
  plVar6 = _DAT_23eede640;
  lVar17 = *(longlong *)(param_1 + 0x38);
  plVar15 = _DAT_23eede640 + 9;
  lVar5 = *(longlong *)(lVar17 + 8);
  _DAT_23eede640[0xf] = lVar5;
  *(longlong **)(lVar17 + 8) = plVar15;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar15 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar15;
    if (plVar15 != (longlong *)0x0) {
      *plVar15 = *plVar15 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  iVar14 = FUN_23a35f020(plVar2);
  if (iVar14 == -1) {
    plStack_88 = *(longlong **)(param_1 + 0x70);
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    uVar24 = 0xf9;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    if (iVar14 == 0) {
      *plVar3 = *plVar3 + 1;
      plVar22 = plVar3;
LAB_23e88f16c:
      plVar15 = (longlong *)FUN_23e8bc2f0(plVar22,_DAT_23eedc938);
      if (plVar15 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar18 = (longlong *)0x0;
        uVar24 = 0x103;
        plStack_d0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar15 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      plVar16 = (longlong *)FUN_23e8bd600(param_1,plVar15);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (plVar16 == (longlong *)0x0) {
        plStack_88 = *(longlong **)(param_1 + 0x70);
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plVar19 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar15 = (longlong *)0x0;
        uVar24 = 0x103;
        plStack_d0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar18 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      lVar17 = *plVar16 + -1;
      if (plVar16[2] == 1) {
        *plVar16 = lVar17;
        if ((int)plVar16[3] != 3) goto LAB_23e88f1c3;
        if (lVar17 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        lVar17 = FUN_23e8dbcd0();
        if (lVar17 == 0) {
          FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
          plVar15 = (longlong *)0x0;
LAB_23e890535:
          plStack_d0 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          uVar24 = 0x104;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          goto LAB_23e88fef0;
        }
        plVar16 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eedc948);
        if (plVar16 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          plVar19 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar15 = (longlong *)0x0;
          uVar24 = 0x104;
          plStack_d0 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar16 = (longlong *)0x0;
          goto LAB_23e88fef0;
        }
        lVar17 = FUN_23e8dbcd0();
        if (lVar17 == 0) {
          FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plVar15 = (longlong *)0x0;
          goto LAB_23e890535;
        }
        plVar18 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eedcbc0);
        if (plVar18 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plStack_d0 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar15 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          uVar24 = 0x104;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          goto LAB_23e88fef0;
        }
        *(undefined4 *)(plVar6 + 5) = 0x104;
        plStack_78 = plVar22;
        plStack_70 = plVar18;
        plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar16,&plStack_78);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        *plVar18 = *plVar18 + -1;
        if (*plVar18 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        if (plVar15 == (longlong *)0x0) {
          plStack_88 = *(longlong **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e890535;
        }
      }
      else {
        *plVar16 = lVar17;
LAB_23e88f1c3:
        if (lVar17 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        *plVar22 = *plVar22 + 1;
        plVar15 = plVar22;
      }
      plVar16 = (longlong *)FUN_23e8bc2f0(plVar4,_DAT_23eedc938);
      if (plVar16 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar24 = 0x108;
        plStack_d0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar18 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      plVar18 = (longlong *)FUN_23e8bd600(param_1,plVar16);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (plVar18 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        plVar18 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar24 = 0x108;
        plStack_d0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar16 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      lVar17 = *plVar18 + -1;
      if (plVar18[2] == 1) {
        *plVar18 = lVar17;
        if ((int)plVar18[3] != 3) goto LAB_23e88f22d;
        if (lVar17 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        lVar17 = FUN_23e8dbcd0();
        if (lVar17 == 0) {
          FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
          plVar18 = (longlong *)0x0;
LAB_23e88fdec:
          plStack_d0 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          uVar24 = 0x109;
          plStack_b8 = (longlong *)0x0;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          goto LAB_23e88fef0;
        }
        plVar16 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eedc948);
        if (plVar16 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          plVar16 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar24 = 0x109;
          plStack_d0 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar19 = (longlong *)0x0;
          goto LAB_23e88fef0;
        }
        lVar17 = FUN_23e8dbcd0();
        if (lVar17 == 0) {
          FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plVar18 = (longlong *)0x0;
          goto LAB_23e88fdec;
        }
        plVar19 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eedcbc0);
        if (plVar19 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plStack_d0 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar18 = (longlong *)0x0;
          uVar24 = 0x109;
          plStack_b8 = (longlong *)0x0;
          plStack_c0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          goto LAB_23e88fef0;
        }
        *(undefined4 *)(plVar6 + 5) = 0x109;
        plStack_78 = plVar4;
        plStack_70 = plVar19;
        plVar18 = (longlong *)FUN_23e94ed00(param_1,plVar16,&plStack_78);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        if (plVar18 == (longlong *)0x0) {
          plStack_88 = *(longlong **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e88fdec;
        }
      }
      else {
        *plVar18 = lVar17;
LAB_23e88f22d:
        if (lVar17 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        *plVar4 = *plVar4 + 1;
        plVar18 = plVar4;
      }
      lVar17 = FUN_23e8dbcd0();
      if (lVar17 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
        plVar16 = (longlong *)0x0;
LAB_23e890f0f:
        plStack_d0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        uVar24 = 0x10e;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      plVar19 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eedcbc8);
      if (plVar19 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar24 = 0x10e;
        plStack_d0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_f0 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      lVar17 = FUN_23e8dbcd0();
      if (lVar17 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
        lVar17 = *plVar19;
        *plVar19 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        plVar16 = (longlong *)0x0;
        goto LAB_23e890f0f;
      }
      plVar20 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eedcbd0);
      if (plVar20 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        lVar17 = *plVar19;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar19 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar19[1] + 0x30))();
        }
        plStack_d0 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        uVar24 = 0x10e;
        plStack_b8 = (longlong *)0x0;
        plStack_c0 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        goto LAB_23e88fef0;
      }
      *(undefined4 *)(plVar6 + 5) = 0x10e;
      plStack_78 = plVar15;
      plStack_70 = plVar18;
      plStack_68 = plVar20;
      plVar16 = (longlong *)FUN_23e956150(param_1,plVar19,&plStack_78);
      lVar17 = *plVar19;
      *plVar19 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      *plVar20 = *plVar20 + -1;
      if (*plVar20 == 0) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
      if (plVar16 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e890f0f;
      }
      lVar17 = FUN_23e8dbcd0();
      if (lVar17 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23eedc940);
        plVar20 = plStack_88;
        uVar25 = auStack_98._0_8_;
        uVar26 = auStack_98._8_8_;
      }
      else {
        *(undefined4 *)(plVar6 + 5) = 0x10f;
        plVar19 = (longlong *)FUN_23e915840(param_1,lVar17,_DAT_23eedcbd8,plVar16);
        if (plVar19 != (longlong *)0x0) {
          plVar21 = (longlong *)FUN_23a388310(plVar19);
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          if (plVar21 != (longlong *)0x0) {
            plVar19 = (longlong *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
            if ((plVar19 == (longlong *)0x0) &&
               (plVar19 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4),
               plVar19 == (longlong *)0x0)) {
              plStack_e8 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
            }
            else {
              plStack_f0 = (longlong *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
              if ((plStack_f0 == (longlong *)0x0) &&
                 (plStack_f0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,4),
                 plStack_f0 == (longlong *)0x0)) {
                plStack_e8 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
              }
              else {
                plStack_e0 = (longlong *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
                if ((plStack_e0 == (longlong *)0x0) &&
                   (plStack_e0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,4),
                   plStack_e0 == (longlong *)0x0)) {
                  plStack_e8 = (longlong *)0x0;
                }
                else {
                  plStack_e8 = (longlong *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
                  if (((plStack_e8 != (longlong *)0x0) ||
                      (plStack_e8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,3,4),
                      plStack_e8 != (longlong *)0x0)) &&
                     (cVar13 = FUN_23a3884a0(param_1,auStack_98,plVar21,4), cVar13 != '\0')) {
                    *plVar21 = *plVar21 + -1;
                    if (*plVar21 == 0) {
                      (**(code **)(plVar21[1] + 0x30))(plVar21);
                    }
                    if (*plVar19 == 0) {
                      (**(code **)(plVar19[1] + 0x30))(plVar19);
                    }
                    if (*plStack_f0 == 0) {
                      (**(code **)(plStack_f0[1] + 0x30))();
                    }
                    if (*plStack_e0 == 0) {
                      (**(code **)(plStack_e0[1] + 0x30))();
                    }
                    if (*plStack_e8 == 0) {
                      (**(code **)(plStack_e8[1] + 0x30))();
                    }
                    lVar17 = *(longlong *)(DAT_23eedc7f0 + 0x20);
                    if (*(char *)(lVar17 + 10) == '\0') {
                      plVar20 = (longlong *)FUN_23a37a020(DAT_23eedc7f0,_DAT_23eedcbe0);
                      if (plVar20 == (longlong *)0x0) goto LAB_23e891320;
                      lVar17 = *plVar20;
LAB_23e891309:
                      if (lVar17 == 0) goto LAB_23e891320;
LAB_23e88f545:
                      iVar14 = FUN_23e97d0c0(plStack_f0);
                      if (iVar14 != -1) {
                        if (iVar14 != 1) {
                          lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar6 = *(longlong **)(lVar17 + 0x28);
                          plVar20 = (longlong *)plVar6[2];
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar17 + 0x30);
                          *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                          if (plVar20 != (longlong *)0x0) {
                            plVar6[2] = 0;
                            *plVar20 = *plVar20 + -1;
                            if (*plVar20 == 0) {
                              (**(code **)(plVar20[1] + 0x30))();
                            }
                          }
                          *plVar6 = *plVar6 + -1;
                          if (*plVar6 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          lVar17 = *(longlong *)(param_1 + 0x10);
                          plVar6[0xf] = 0;
                          puVar23 = *(undefined8 **)(lVar17 + 0xe30);
                          if (puVar23 == (undefined8 *)0x0) {
                            puVar23 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,4);
                          }
                          else {
                            uVar25 = puVar23[3];
                            *(int *)(lVar17 + 0xec4) = *(int *)(lVar17 + 0xec4) + -1;
                            *(undefined8 *)(lVar17 + 0xe30) = uVar25;
                            *puVar23 = 1;
                          }
                          plStack_d0 = (longlong *)0x0;
                          plStack_b8 = (longlong *)0x0;
                          plStack_c0 = (longlong *)0x0;
                          plStack_c8 = (longlong *)0x0;
                          lVar17 = *(longlong *)
                                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                    0x2e8);
                          uVar25 = puVar23[-1];
                          puVar7 = *(undefined8 **)(lVar17 + 8);
                          *puVar7 = puVar23 + -2;
                          pcVar9 = _Py_FalseStruct_exref;
                          puVar23[-2] = lVar17;
                          puVar23[-1] = (ulonglong)((uint)uVar25 & 3) | (ulonglong)puVar7;
                          *(undefined8 **)(lVar17 + 8) = puVar23 + -2;
                          *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                          puVar23[3] = pcVar9;
                          plVar6 = DAT_23ed6ccf0;
                          lVar17 = *DAT_23ed6ccf0;
                          puVar23[4] = DAT_23ed6ccf0;
                          *plVar6 = lVar17 + 2;
                          puVar23[5] = plVar6;
                          *plStack_f0 = *plStack_f0 + 1;
                          puVar23[6] = plStack_f0;
                          goto LAB_23e88f692;
                        }
                        plVar20 = (longlong *)FUN_23e8bc2f0(plVar4,_DAT_23eedc938);
                        if (plVar20 == (longlong *)0x0) {
LAB_23e89194f:
                          plVar21 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar25 = *(undefined8 *)(param_1 + 0x60);
                          uVar26 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          plVar21 = (longlong *)FUN_23a38cc10(param_1,plVar20,_DAT_23eedcb70);
                          *plVar20 = *plVar20 + -1;
                          if (*plVar20 == 0) {
                            (**(code **)(plVar20[1] + 0x30))(plVar20);
                          }
                          if (plVar21 == (longlong *)0x0) goto LAB_23e89194f;
                          plVar20 = (longlong *)FUN_23a388310(plVar21);
                          *plVar21 = *plVar21 + -1;
                          if (*plVar21 == 0) {
                            (**(code **)(plVar21[1] + 0x30))(plVar21);
                          }
                          if (plVar20 == (longlong *)0x0) goto LAB_23e89194f;
                          plStack_c8 = (longlong *)(**(code **)(plVar20[1] + 0xe0))(plVar20);
                          if ((plStack_c8 == (longlong *)0x0) &&
                             (plStack_c8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2),
                             plStack_c8 == (longlong *)0x0)) {
                            plStack_c0 = (longlong *)0x0;
                          }
                          else {
                            plStack_c0 = (longlong *)(**(code **)(plVar20[1] + 0xe0))(plVar20);
                            if (((plStack_c0 != (longlong *)0x0) ||
                                (plStack_c0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2),
                                plStack_c0 != (longlong *)0x0)) &&
                               (cVar13 = FUN_23a3884a0(param_1,auStack_98,plVar20,2), cVar13 != '\0'
                               )) {
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                (**(code **)(plVar20[1] + 0x30))(plVar20);
                              }
                              if (*plStack_c8 == 0) {
                                (**(code **)(plStack_c8[1] + 0x30))();
                              }
                              if (*plStack_c0 == 0) {
                                (**(code **)(plStack_c0[1] + 0x30))();
                              }
                              plVar20 = (longlong *)
                                        FUN_23a388650(param_1,plStack_e8,DAT_23ed6ccf0,0);
                              pcVar9 = PyLong_Type_exref;
                              if (plVar20 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0x114;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_b8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d0 = (longlong *)0x0;
                                goto LAB_23e88fef0;
                              }
                              if ((code *)plStack_c0[1] == PyLong_Type_exref) {
                                plVar21 = (longlong *)
                                          (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) +
                                                      0xe8))(plStack_c0,_DAT_23eedc990);
                              }
                              else {
                                plVar21 = (longlong *)FUN_23e8c1be0();
                              }
                              if (plVar21 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                lVar17 = *plVar20;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar20 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  FUN_23a334bc0(plVar20);
                                }
                                uVar24 = 0x114;
                                plStack_d0 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                goto LAB_23e88fef0;
                              }
                              plStack_b8 = (longlong *)FUN_23e8c09e0(plVar20);
                              lVar17 = *plVar20;
                              *plVar20 = lVar17 + -1;
                              if (lVar17 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              *plVar21 = *plVar21 + -1;
                              if (*plVar21 == 0) {
                                FUN_23a334bc0(plVar21);
                              }
                              if (plStack_b8 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0x114;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_d0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e88fef0;
                              }
                              plVar20 = (longlong *)FUN_23a388650(param_1,plStack_e8,DAT_23ed6ccf8);
                              if (plVar20 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0x115;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_d0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e88fef0;
                              }
                              if ((code *)plStack_c8[1] == pcVar9) {
                                plVar21 = (longlong *)
                                          (**(code **)(*(longlong *)(pcVar9 + 0x60) + 0xe8))
                                                    (plStack_c8,_DAT_23eedc990);
                              }
                              else {
                                plVar21 = (longlong *)FUN_23e8c1be0(plStack_c8);
                              }
                              if (plVar21 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar20 = *plVar20 + -1;
                                if (*plVar20 == 0) {
                                  FUN_23a334bc0(plVar20);
                                }
                                uVar24 = 0x115;
                                plStack_d0 = (longlong *)0x0;
                                goto LAB_23e88fef0;
                              }
                              plStack_d0 = (longlong *)FUN_23e8c09e0(plVar20);
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                FUN_23a334bc0(plVar20);
                              }
                              *plVar21 = *plVar21 + -1;
                              if (*plVar21 == 0) {
                                FUN_23a334bc0(plVar21);
                              }
                              if (plStack_d0 == (longlong *)0x0) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar24 = 0x115;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e88fef0;
                              }
                              iVar14 = FUN_23a35f020(plVar2);
                              if (iVar14 == -1) {
                                auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar24 = 0x118;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e88fef0;
                              }
                              if (iVar14 == 0) {
LAB_23e8917b6:
                                puVar23 = (undefined8 *)
                                          FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),4);
                                pcVar9 = _Py_TrueStruct_exref;
                                uVar25 = *(undefined8 *)(param_1 + 0x38);
                                puVar23[3] = _Py_TrueStruct_exref;
                                *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                                *plStack_b8 = *plStack_b8 + 1;
                                puVar23[4] = plStack_b8;
                                *plStack_d0 = *plStack_d0 + 1;
                                puVar23[5] = plStack_d0;
                                *plStack_f0 = *plStack_f0 + 1;
                                puVar23[6] = plStack_f0;
                                FUN_23ebf6b20(uVar25);
LAB_23e88f692:
                                *plVar22 = *plVar22 + -1;
                                if (*plVar22 == 0) {
                                  (**(code **)(plVar22[1] + 0x30))(plVar22);
                                }
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                                }
                                *plVar18 = *plVar18 + -1;
                                if (*plVar18 == 0) {
                                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                                }
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                }
                                *plVar19 = *plVar19 + -1;
                                if (*plVar19 == 0) {
                                  (**(code **)(plVar19[1] + 0x30))(plVar19);
                                }
                                lVar17 = *plStack_f0;
                                *plStack_f0 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
                                }
                                lVar17 = *plStack_e0;
                                *plStack_e0 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                                }
                                lVar17 = *plStack_e8;
                                *plStack_e8 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
                                }
                                if ((plStack_c8 != (longlong *)0x0) &&
                                   (lVar17 = *plStack_c8, *plStack_c8 = lVar17 + -1,
                                   lVar17 + -1 == 0)) {
                                  (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                                }
                                if ((plStack_c0 != (longlong *)0x0) &&
                                   (lVar17 = *plStack_c0, *plStack_c0 = lVar17 + -1,
                                   lVar17 + -1 == 0)) {
                                  (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                                }
                                if ((plStack_b8 != (longlong *)0x0) &&
                                   (lVar17 = *plStack_b8, *plStack_b8 = lVar17 + -1,
                                   lVar17 + -1 == 0)) {
                                  (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                                }
                                if ((plStack_d0 != (longlong *)0x0) &&
                                   (lVar17 = *plStack_d0, *plStack_d0 = lVar17 + -1,
                                   lVar17 + -1 == 0)) {
                                  (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                                }
                                lVar17 = *plVar1;
                                *plVar1 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                                }
                                lVar17 = *plVar3;
                                *plVar3 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                                }
                                lVar17 = *plVar4;
                                *plVar4 = lVar17 + -1;
                                if (lVar17 + -1 == 0) {
                                  (**(code **)(plVar4[1] + 0x30))(plVar4);
                                }
                                *plVar2 = *plVar2 + -1;
                                if (*plVar2 != 0) {
                                  return puVar23;
                                }
                                (**(code **)(plVar2[1] + 0x30))(plVar2);
                                return puVar23;
                              }
                              plStack_78 = plStack_b8;
                              plVar20 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedca70);
                              if (plVar20 != (longlong *)0x0) {
                                cVar13 = FUN_23e8bf180(&plStack_78,plVar20);
                                *plVar20 = *plVar20 + -1;
                                if (*plVar20 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (cVar13 != '\0') {
                                  plStack_b8 = plStack_78;
                                  plStack_78 = plStack_d0;
                                  plVar20 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedcb00);
                                  if (plVar20 != (longlong *)0x0) {
                                    cVar13 = FUN_23e8bf180(&plStack_78,plVar20);
                                    *plVar20 = *plVar20 + -1;
                                    if (*plVar20 == 0) {
                                      FUN_23a334bc0(plVar20);
                                    }
                                    if (cVar13 != '\0') {
                                      plStack_d0 = plStack_78;
                                      goto LAB_23e8917b6;
                                    }
                                  }
                                  auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                  uVar24 = 0x11a;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e88fef0;
                                }
                              }
                              auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              uVar24 = 0x119;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23e88fef0;
                            }
                          }
                          plVar21 = plStack_88;
                          uVar25 = auStack_98._0_8_;
                          uVar26 = auStack_98._8_8_;
                          plStack_88 = (longlong *)0x0;
                          auStack_98 = (undefined1  [16])0x0;
                          *plVar20 = *plVar20 + -1;
                          if (*plVar20 == 0) {
                            (**(code **)(plVar20[1] + 0x30))(plVar20);
                          }
                          plStack_88 = (longlong *)0x0;
                          auStack_98 = (undefined1  [16])0x0;
                          if ((plStack_c8 != (longlong *)0x0) &&
                             (lVar17 = *plStack_c8, *plStack_c8 = lVar17 + -1, lVar17 + -1 == 0)) {
                            (**(code **)(plStack_c8[1] + 0x30))();
                          }
                          if ((plStack_c0 != (longlong *)0x0) &&
                             (lVar17 = *plStack_c0, *plStack_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
                            (**(code **)(plStack_c0[1] + 0x30))();
                          }
                        }
                        uVar24 = 0x113;
                        plStack_d0 = (longlong *)0x0;
                        plStack_b8 = (longlong *)0x0;
                        plStack_c0 = (longlong *)0x0;
                        plStack_c8 = (longlong *)0x0;
                        auStack_98._8_8_ = uVar26;
                        auStack_98._0_8_ = uVar25;
                        plStack_88 = plVar21;
                        goto LAB_23e88fef0;
                      }
                      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_88 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      iVar14 = *(int *)(lVar17 + 0xc);
                      if (*(int *)(lVar17 + 0xc) == 0) {
                        *(int *)(lVar17 + 0xc) = DAT_23ec1555c;
                        iVar14 = DAT_23ec1555c;
                        DAT_23ec1555c = DAT_23ec1555c + 1;
                      }
                      if (_DAT_23ec15540 != iVar14) {
                        _DAT_23ec15540 = iVar14;
                        _DAT_23eede630 =
                             FUN_23e8cbd60(lVar17,_DAT_23eedcbe0,
                                           *(undefined8 *)(_DAT_23eedcbe0 + 0x18));
                      }
                      if (-1 < _DAT_23eede630) {
                        lVar5 = lVar17 + 0x20 + (1L << (*(byte *)(lVar17 + 9) & 0x3f));
                        if (*(longlong *)(lVar5 + 8 + _DAT_23eede630 * 0x10) != 0)
                        goto LAB_23e88f545;
                        _DAT_23eede630 =
                             FUN_23e8cbd60(lVar17,_DAT_23eedcbe0,
                                           *(undefined8 *)(_DAT_23eedcbe0 + 0x18));
                        if (-1 < _DAT_23eede630) {
                          lVar17 = *(longlong *)(lVar5 + 8 + _DAT_23eede630 * 0x10);
                          goto LAB_23e891309;
                        }
                      }
LAB_23e891320:
                      plVar20 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedcbe0);
                      if ((plVar20 != (longlong *)0x0) && (*plVar20 != 0)) goto LAB_23e88f545;
                      FUN_23e915740(param_1,auStack_98,_DAT_23eedcbe0);
                    }
                    plStack_d0 = (longlong *)0x0;
                    uVar24 = 0x111;
                    plStack_b8 = (longlong *)0x0;
                    plStack_c0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    goto LAB_23e88fef0;
                  }
                }
              }
            }
            plVar20 = plStack_88;
            uVar25 = auStack_98._0_8_;
            uVar26 = auStack_98._8_8_;
            plStack_88 = (longlong *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            *plVar21 = *plVar21 + -1;
            if (*plVar21 == 0) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            plStack_88 = (longlong *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            if ((plStack_f0 != (longlong *)0x0) &&
               (lVar17 = *plStack_f0, *plStack_f0 = lVar17 + -1, lVar17 + -1 == 0)) {
              (**(code **)(plStack_f0[1] + 0x30))();
            }
            if ((plStack_e0 != (longlong *)0x0) &&
               (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
              (**(code **)(plStack_e0[1] + 0x30))();
            }
            if ((plStack_e8 != (longlong *)0x0) &&
               (lVar17 = *plStack_e8, *plStack_e8 = lVar17 + -1, lVar17 + -1 == 0)) {
              (**(code **)(plStack_e8[1] + 0x30))();
            }
            goto LAB_23e890a9e;
          }
        }
        uVar25 = *(undefined8 *)(param_1 + 0x60);
        plVar20 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar26 = *(undefined8 *)(param_1 + 0x68);
      }
LAB_23e890a9e:
      plVar19 = (longlong *)0x0;
      uVar24 = 0x10f;
      plStack_d0 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      auStack_98._8_8_ = uVar26;
      auStack_98._0_8_ = uVar25;
      plStack_88 = plVar20;
      goto LAB_23e88fef0;
    }
    plVar15 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedcb00);
    if (plVar15 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      plVar19 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar18 = (longlong *)0x0;
      plVar22 = (longlong *)0x0;
      uVar24 = 0xfc;
      plStack_d0 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar15 = (longlong *)0x0;
      goto LAB_23e88fef0;
    }
    plVar22 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedcb00);
    if (plVar22 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar15 = *plVar15 + -1;
      plVar22 = (longlong *)0x0;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
LAB_23e88fc60:
      plStack_d0 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      uVar24 = 0xfc;
      plStack_c0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      goto LAB_23e88fef0;
    }
    plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedcb20);
    if (plVar16 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *plVar22 = *plVar22 + -1;
      if (*plVar22 == 0) {
        (**(code **)(plVar22[1] + 0x30))(plVar22);
      }
      plStack_d0 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar22 = (longlong *)0x0;
      uVar24 = 0xfc;
      plStack_c0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      goto LAB_23e88fef0;
    }
    plVar18 = (longlong *)FUN_23e8c09e0(plVar22,plVar16);
    *plVar22 = *plVar22 + -1;
    if (*plVar22 == 0) {
      (**(code **)(plVar22[1] + 0x30))(plVar22);
    }
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    pcVar9 = _Py_NoneStruct_exref;
    if (plVar18 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      plStack_d0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plVar22 = (longlong *)0x0;
      uVar24 = 0xfc;
      plStack_c0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar18 = (longlong *)0x0;
      goto LAB_23e88fef0;
    }
    lVar17 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar15,plVar18,_Py_NoneStruct_exref);
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    lVar5 = *(longlong *)(param_1 + 0x10);
    plVar15 = *(longlong **)(lVar5 + 0xe20);
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar8 = plVar15[3];
      *(int *)(lVar5 + 0xebc) = *(int *)(lVar5 + 0xebc) + -1;
      *(longlong *)(lVar5 + 0xe20) = lVar8;
      *plVar15 = 1;
    }
    pcVar10 = _PyRuntime_exref;
    plVar15[4] = 0;
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar10 + 0x1f8) + 0x10) + 0x2e8);
    lVar8 = plVar15[-1];
    puVar23 = *(undefined8 **)(lVar5 + 8);
    *puVar23 = plVar15 + -2;
    uVar25 = DAT_23eedca70;
    plVar15[-2] = lVar5;
    plVar15[-1] = (ulonglong)((uint)lVar8 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar5 + 8) = plVar15 + -2;
    plVar15[3] = lVar17;
    plVar22 = (longlong *)FUN_23a38cc10(param_1,plVar2,uVar25);
    if (plVar22 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedca70);
      if (plVar16 != (longlong *)0x0) {
        plVar18 = (longlong *)FUN_23a38cc10(param_1,plVar2,DAT_23eedcb10);
        if (plVar18 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar22 = *plVar22 + -1;
          if (*plVar22 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22,0);
          }
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          goto LAB_23e890c01;
        }
        plVar19 = (longlong *)FUN_23e8c09e0(plVar16);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        *plVar18 = *plVar18 + -1;
        if (*plVar18 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        if (plVar19 != (longlong *)0x0) {
          lVar17 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar22,plVar19,pcVar9);
          *plVar22 = *plVar22 + -1;
          if (*plVar22 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          plVar15[4] = lVar17;
          plVar22 = (longlong *)FUN_23a38cc10(param_1,plVar3,plVar15);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plVar22 != (longlong *)0x0) goto LAB_23e88f16c;
          plStack_88 = *(longlong **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e88fc60;
        }
      }
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar22 = *plVar22 + -1;
      if (*plVar22 == 0) {
        (**(code **)(plVar22[1] + 0x30))(plVar22);
      }
    }
LAB_23e890c01:
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    uVar24 = 0xfd;
  }
  plStack_d0 = (longlong *)0x0;
  plVar18 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  plVar19 = (longlong *)0x0;
  plStack_b8 = (longlong *)0x0;
  plVar16 = (longlong *)0x0;
  plVar22 = (longlong *)0x0;
  plStack_c0 = (longlong *)0x0;
  plStack_c8 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_f0 = (longlong *)0x0;
LAB_23e88fef0:
  plVar21 = plStack_88;
  plVar20 = DAT_23ed6a4f8;
  if (plStack_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar20 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar21 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar20[2] = 0;
    plVar20[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar17 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar20 + 0x24) = uVar24;
    lVar17 = *(longlong *)(lVar17 + 0x10);
    *(undefined4 *)(plVar20 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(lVar17 + 0x2e8);
    lVar5 = plVar20[-1];
    puVar23 = *(undefined8 **)(lVar17 + 8);
    *puVar23 = plVar20 + -2;
    plVar20[-2] = lVar17;
    plVar20[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar17 + 8) = plVar20 + -2;
    plVar21 = plVar20;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  else if ((longlong *)plStack_88[3] != plVar6) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar20 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar20[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar17 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar20 + 0x24) = uVar24;
    *(undefined4 *)(plVar20 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
    lVar5 = plVar20[-1];
    puVar23 = *(undefined8 **)(lVar17 + 8);
    *puVar23 = plVar20 + -2;
    plVar20[-2] = lVar17;
    plVar20[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar17 + 8) = plVar20 + -2;
    plVar20[2] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    plVar21 = plVar20;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  plStack_88 = plVar21;
  FUN_23e8bba40(plVar6,"oooooooooooooooo",plVar1,plVar3,plVar4,plVar2,plVar22,plVar15,plVar18,
                plVar16,plVar19,plStack_f0,plStack_e0,plStack_e8,plStack_c8,plStack_c0,plStack_b8,
                plStack_d0);
  if (_DAT_23eede640 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eede640 = (longlong *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar17 + 0x28);
  plVar20 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar20 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar20 = plStack_88;
  auVar11 = auStack_98;
  plVar6[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  plStack_88 = (longlong *)0x0;
  if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
    (**(code **)(plVar22[1] + 0x30))(plVar22);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar17 = *plStack_f0, *plStack_f0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar17 = *plStack_e8, *plStack_e8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar17 = *plStack_c8, *plStack_c8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar17 = *plStack_c0, *plStack_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar17 = *plStack_b8, *plStack_b8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  if ((plStack_d0 != (longlong *)0x0) &&
     (lVar17 = *plStack_d0, *plStack_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  lVar17 = *plVar1;
  *plVar1 = lVar17 + -1;
  auStack_98 = auVar11;
  plStack_88 = plVar20;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar17 = *plVar3;
  *plVar3 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar17 = *plVar4;
  *plVar4 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,plStack_88);
  return (undefined8 *)0x0;
}
