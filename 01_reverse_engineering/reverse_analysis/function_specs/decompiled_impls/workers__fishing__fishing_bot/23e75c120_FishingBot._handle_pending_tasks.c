/* ===== 23e75c120 workers.fishing.fishing_bot:FishingBot._handle_pending_tasks ===== */
/* ghidra_name=FUN_23e75c120 entry=23e75c120 size=4944 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e75c120(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  undefined8 *puVar17;
  undefined4 uVar18;
  code *pcVar19;
  longlong *plVar20;
  uint uVar21;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar22;
  undefined8 *puStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar12 = _DAT_23eedadc8;
  uVar22 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eedadc8 == (longlong *)0x0) {
LAB_23e75c16d:
    _DAT_23eedadc8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedafa0,DAT_23eedaeb8,0x24);
  }
  else {
    lVar16 = *_DAT_23eedadc8;
    if (1 < lVar16) {
      *_DAT_23eedadc8 = lVar16 + -1;
      goto LAB_23e75c16d;
    }
    if (_DAT_23eedadc8[2] != 0) {
      *_DAT_23eedadc8 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e75c16d;
    }
  }
  plVar7 = _DAT_23eedadc8;
  lVar16 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eedadc8 + 9;
  lVar4 = *(longlong *)(lVar16 + 8);
  _DAT_23eedadc8[0xf] = lVar4;
  *(longlong **)(lVar16 + 8) = plVar12;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  uVar5 = DAT_23eed89b0;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
  if (plVar12 == (longlong *)0x0) {
    puVar17 = *(undefined8 **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x3cd;
    uVar21 = 2;
    plVar14 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = (longlong *)0x0;
    plVar13 = DAT_23ed6a4f8;
  }
  else {
    *(undefined4 *)(plVar7 + 5) = 0x3cd;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar12,DAT_23eed8d38);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      puVar17 = *(undefined8 **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      plVar15 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x3cd;
      uVar21 = 2;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar14 = *(longlong **)(param_1 + 0x68);
      plVar13 = DAT_23ed6a4f8;
    }
    else {
      iVar11 = FUN_23a35f020(plVar13);
      lVar16 = *plVar13 + -1;
      if (iVar11 == -1) {
        puVar17 = *(undefined8 **)(param_1 + 0x60);
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = *(longlong **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar13 = lVar16;
        if (lVar16 == 0) {
          plVar15 = (longlong *)0x0;
          (**(code **)(plVar13[1] + 0x30))(plVar13);
          uVar18 = 0x3cd;
          uVar21 = 2;
          plVar13 = DAT_23ed6a4f8;
        }
        else {
          uVar18 = 0x3cd;
          uVar21 = 2;
          plVar15 = (longlong *)0x0;
          plVar13 = DAT_23ed6a4f8;
        }
      }
      else {
        *plVar13 = lVar16;
        if (lVar16 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        pcVar19 = _Py_NoneStruct_exref;
        if (iVar11 != 0) {
          lVar16 = *(longlong *)(param_1 + 0x38);
          lVar4 = *(longlong *)(lVar16 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar12 = *(longlong **)(lVar4 + 0x28);
          plVar7 = (longlong *)plVar12[2];
          *(undefined8 *)(lVar16 + 8) = *(undefined8 *)(lVar4 + 0x30);
          *(undefined4 *)(plVar12 + 8) = 0xffffffff;
          if (plVar7 != (longlong *)0x0) {
            plVar12[2] = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar12[0xf] = 0;
LAB_23e75c926:
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))(plVar3);
            return pcVar19;
          }
          return pcVar19;
        }
        cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_TrueStruct_exref);
        lVar16 = _DAT_23eed9310;
        if (cVar10 == '\0') {
          puVar17 = *(undefined8 **)(param_1 + 0x60);
          plVar12 = *(longlong **)(param_1 + 0x70);
          plVar15 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar18 = 0x3d0;
          uVar21 = 2;
          plVar14 = *(longlong **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
        }
        else {
          *(undefined4 *)(plVar7 + 5) = 0x3d3;
          plVar12 = (longlong *)
                    FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar16 + 0x18));
          if (plVar12 == (longlong *)0x0) {
            puVar17 = *(undefined8 **)(param_1 + 0x60);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uVar18 = 0x3d3;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar21 = 2;
            plVar14 = *(longlong **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            plVar13 = DAT_23ed6a4f8;
          }
          else {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *(undefined4 *)(plVar7 + 5) = 0x3d4;
            plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9318);
            if (plVar12 == (longlong *)0x0) {
              puVar17 = *(undefined8 **)(param_1 + 0x60);
              plVar12 = *(longlong **)(param_1 + 0x70);
              uVar18 = 0x3d4;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar21 = 2;
              plVar14 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar15 = (longlong *)0x0;
              plVar13 = DAT_23ed6a4f8;
            }
            else {
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *(undefined4 *)(plVar7 + 5) = 0x3d5;
              plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9320);
              if (plVar12 == (longlong *)0x0) {
                puVar17 = *(undefined8 **)(param_1 + 0x60);
                plVar12 = *(longlong **)(param_1 + 0x70);
                uVar18 = 0x3d5;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 2;
                plVar14 = *(longlong **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar15 = (longlong *)0x0;
                plVar13 = DAT_23ed6a4f8;
              }
              else {
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                iVar11 = FUN_23a35f020(plVar2);
                if (iVar11 == -1) {
                  puVar17 = *(undefined8 **)(param_1 + 0x60);
                  plVar12 = *(longlong **)(param_1 + 0x70);
                  plVar15 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar18 = 0x3d8;
                  uVar21 = 2;
                  plVar14 = *(longlong **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar13 = DAT_23ed6a4f8;
                }
                else {
                  if (iVar11 != 0) {
                    lVar16 = FUN_23e8e0e20();
                    if (lVar16 == 0) {
                      FUN_23e915740(param_1,&puStack_78,DAT_23eed8988);
                      uVar18 = 0x3d9;
                      uVar21 = 2;
                      plVar15 = (longlong *)0x0;
                      puVar17 = puStack_78;
                      plVar12 = plStack_68;
                      plVar14 = plStack_70;
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e75c832;
                    }
                    plVar12 = (longlong *)FUN_23e8bc2f0(lVar16,_DAT_23eed9328);
                    if (plVar12 == (longlong *)0x0) {
                      puVar17 = *(undefined8 **)(param_1 + 0x60);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0x3d9;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar21 = 2;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar15 = (longlong *)0x0;
                      plVar14 = *(longlong **)(param_1 + 0x68);
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e75c832;
                    }
                    cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar12);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    lVar16 = _DAT_23eed9330;
                    if (cVar10 == '\0') {
                      puVar17 = *(undefined8 **)(param_1 + 0x60);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      plVar15 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar18 = 0x3d9;
                      uVar21 = 2;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar14 = *(longlong **)(param_1 + 0x68);
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e75c832;
                    }
                    *(undefined4 *)(plVar7 + 5) = 0x3da;
                    plVar12 = (longlong *)
                              FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                            *(undefined8 *)(lVar16 + 0x18));
                    if (plVar12 == (longlong *)0x0) {
                      puVar17 = *(undefined8 **)(param_1 + 0x60);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0x3da;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar21 = 2;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar15 = (longlong *)0x0;
                      plVar14 = *(longlong **)(param_1 + 0x68);
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e75c832;
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    *(undefined4 *)(plVar7 + 5) = 0x3db;
                    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9338);
                    if (plVar12 == (longlong *)0x0) {
                      puVar17 = *(undefined8 **)(param_1 + 0x60);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0x3db;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar21 = 2;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar15 = (longlong *)0x0;
                      plVar14 = *(longlong **)(param_1 + 0x68);
                      plVar13 = DAT_23ed6a4f8;
                      goto joined_r0x00023e75c832;
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                  }
                  iVar11 = FUN_23a35f020(plVar3);
                  if (iVar11 == -1) {
                    puVar17 = *(undefined8 **)(param_1 + 0x60);
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    plVar15 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar18 = 0x3de;
                    uVar21 = 2;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar14 = *(longlong **)(param_1 + 0x68);
                    plVar13 = DAT_23ed6a4f8;
                  }
                  else {
                    if (iVar11 != 0) {
                      lVar16 = FUN_23e8e0e20();
                      if (lVar16 == 0) {
                        FUN_23e915740(param_1,&puStack_78,DAT_23eed8988);
                        uVar18 = 0x3df;
                        uVar21 = 2;
                        plVar15 = (longlong *)0x0;
                        puVar17 = puStack_78;
                        plVar12 = plStack_68;
                        plVar14 = plStack_70;
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                      plVar12 = (longlong *)FUN_23e8bc2f0(lVar16,DAT_23eed8f18);
                      if (plVar12 == (longlong *)0x0) {
                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0x3df;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar21 = 2;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar15 = (longlong *)0x0;
                        plVar14 = *(longlong **)(param_1 + 0x68);
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                      cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      lVar16 = DAT_23eed9340;
                      if (cVar10 == '\0') {
                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        plVar15 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar18 = 0x3df;
                        uVar21 = 2;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = *(longlong **)(param_1 + 0x68);
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                      *(undefined4 *)(plVar7 + 5) = 0x3e0;
                      plVar12 = (longlong *)
                                FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                              *(undefined8 *)(lVar16 + 0x18));
                      if (plVar12 == (longlong *)0x0) {
                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0x3e0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar21 = 2;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar15 = (longlong *)0x0;
                        plVar14 = *(longlong **)(param_1 + 0x68);
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      *(undefined4 *)(plVar7 + 5) = 0x3e1;
                      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9348);
                      if (plVar12 == (longlong *)0x0) {
                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0x3e1;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar21 = 2;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar15 = (longlong *)0x0;
                        plVar14 = *(longlong **)(param_1 + 0x68);
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                    }
                    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8978);
                    plVar15 = (longlong *)0x0;
                    if (plVar12 != (longlong *)0x0) {
                      plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23ed6ce40);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      puVar17 = DAT_23eed8b60;
                      lVar16 = DAT_23ed6cce8;
                      if (plVar14 == (longlong *)0x0) {
                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        plVar15 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar18 = 0x3e4;
                        uVar21 = 2;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = *(longlong **)(param_1 + 0x68);
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                      lVar4 = *(longlong *)(param_1 + 0x10);
                      plVar12 = *(longlong **)(DAT_23ed6cce8 + 0x20);
                      iVar11 = *(int *)(lVar4 + 0x1410);
                      *plVar12 = *plVar12 + 1;
                      if (iVar11 == 0) {
                        plVar13 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
                        plVar12 = *(longlong **)(lVar16 + 0x20);
                      }
                      else {
                        iVar11 = iVar11 + -1;
                        *(int *)(lVar4 + 0x1410) = iVar11;
                        plVar13 = *(longlong **)(lVar4 + 0x1190 + (longlong)iVar11 * 8);
                        *plVar13 = 1;
                      }
                      lVar16 = *(longlong *)(lVar16 + 0x28);
                      plVar13[4] = (longlong)plVar12;
                      plVar13[5] = lVar16;
                      plVar13[2] = 0;
                      plVar13[3] = 1;
                      *(undefined4 *)(plVar7 + 5) = 0x3e4;
                      puStack_78 = puVar17;
                      plStack_70 = plVar13;
                      plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar14,&puStack_78);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (plVar15 != (longlong *)0x0) {
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar15,DAT_23eed9350);
                        if (plVar12 != (longlong *)0x0) {
                          *(undefined4 *)(plVar7 + 5) = 0x3e5;
                          plVar14 = (longlong *)FUN_23e91a870(param_1,plVar12);
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if (plVar14 != (longlong *)0x0) {
                            plVar12 = (longlong *)FUN_23ebf7180(plVar14);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            puVar17 = DAT_23ed6a4e0;
                            if (plVar12 != (longlong *)0x0) {
                              if (DAT_23ed6a4e0 == (undefined8 *)0x0) {
                                puVar17 = (undefined8 *)FUN_23a33a530(&DAT_23ec0fb60);
                              }
                              else {
                                puVar6 = (undefined8 *)*DAT_23ed6a4e0;
                                *DAT_23ed6a4e0 = 1;
                                DAT_23ed6a4e0 = puVar6;
                                DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
                              }
                              pcVar19 = _PyRuntime_exref;
                              puVar17[2] = plVar12;
                              *plVar12 = *plVar12 + 1;
                              lVar16 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) +
                                        0x2e8);
                              uVar5 = puVar17[-1];
                              puVar6 = *(undefined8 **)(lVar16 + 8);
                              *puVar6 = puVar17 + -2;
                              uVar9 = _DAT_23eedaff8;
                              uVar8 = DAT_23eed9378;
                              puVar17[-2] = lVar16;
                              puVar17[-1] = (ulonglong)((uint)uVar5 & 3) | (ulonglong)puVar6;
                              *(undefined8 **)(lVar16 + 8) = puVar17 + -2;
                              uVar22 = 0;
                              puStack_78 = puVar17;
                              plVar14 = (longlong *)
                                        FUN_23e91ecd0(FUN_23e75d510,DAT_23eedaeb8,DAT_23eed90c0,
                                                      uVar8,uVar9,&puStack_78,1,0x78);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              plVar12 = (longlong *)FUN_23e8bd690(param_1);
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                (**(code **)(plVar14[1] + 0x30))(plVar14);
                              }
                              if (plVar12 != (longlong *)0x0) {
                                iVar11 = FUN_23a35f020(plVar12);
                                uVar21 = (uint)(iVar11 != 0);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                                }
                                lVar16 = DAT_23eed9358;
                                if (iVar11 != 0) {
                                  *(undefined4 *)(plVar7 + 5) = 999;
                                  plVar12 = (longlong *)
                                            FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                          *(undefined8 *)(lVar16 + 0x18));
                                  if (plVar12 == (longlong *)0x0) {
                                    puVar17 = *(undefined8 **)(param_1 + 0x60);
                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                    uVar21 = 1;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar18 = 999;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar14 = *(longlong **)(param_1 + 0x68);
                                    plVar13 = DAT_23ed6a4f8;
                                    goto joined_r0x00023e75c832;
                                  }
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                                  }
                                  *(undefined4 *)(plVar7 + 5) = 1000;
                                  plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9360);
                                  if (plVar12 == (longlong *)0x0) {
                                    puVar17 = *(undefined8 **)(param_1 + 0x60);
                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                    uVar18 = 1000;
                                    uVar21 = 1;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plVar14 = *(longlong **)(param_1 + 0x68);
                                    plVar13 = DAT_23ed6a4f8;
                                    goto joined_r0x00023e75c832;
                                  }
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                                  }
                                }
                                *(undefined4 *)(plVar7 + 5) = 0x3eb;
                                plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9368);
                                if (plVar12 == (longlong *)0x0) {
                                  puVar17 = *(undefined8 **)(param_1 + 0x60);
                                  plVar12 = *(longlong **)(param_1 + 0x70);
                                  uVar18 = 0x3eb;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar14 = *(longlong **)(param_1 + 0x68);
                                  plVar13 = DAT_23ed6a4f8;
                                }
                                else {
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                                  }
                                  lVar16 = DAT_23eed9090;
                                  *(undefined4 *)(plVar7 + 5) = 0x3ef;
                                  plVar12 = (longlong *)
                                            FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                                          *(undefined8 *)(lVar16 + 0x18));
                                  if (plVar12 == (longlong *)0x0) {
                                    puVar17 = *(undefined8 **)(param_1 + 0x60);
                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                    uVar18 = 0x3ef;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar14 = *(longlong **)(param_1 + 0x68);
                                    plVar13 = DAT_23ed6a4f8;
                                  }
                                  else {
                                    *plVar12 = *plVar12 + -1;
                                    if (*plVar12 == 0) {
                                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                                    }
                                    cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,
                                                           _Py_FalseStruct_exref);
                                    if (cVar10 == '\0') {
                                      puVar17 = *(undefined8 **)(param_1 + 0x60);
                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                      uVar18 = 0x3f1;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plVar14 = *(longlong **)(param_1 + 0x68);
                                      plVar13 = DAT_23ed6a4f8;
                                    }
                                    else {
                                      lVar16 = FUN_23e8e0e20();
                                      if (lVar16 == 0) {
                                        FUN_23e915740(param_1,&puStack_78,DAT_23eed8988);
                                        uVar18 = 0x3f2;
                                        puVar17 = puStack_78;
                                        plVar12 = plStack_68;
                                        plVar14 = plStack_70;
                                        plVar13 = DAT_23ed6a4f8;
                                      }
                                      else {
                                        plVar12 = (longlong *)FUN_23e8bc2f0(lVar16,DAT_23eed8990);
                                        if (plVar12 != (longlong *)0x0) {
                                          cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar12);
                                          *plVar12 = *plVar12 + -1;
                                          if (*plVar12 == 0) {
                                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                                          }
                                          if (cVar10 != '\0') {
                                            lVar16 = *(longlong *)
                                                      (*(longlong *)(param_1 + 0x38) + 8);
                                            plVar12 = *(longlong **)(lVar16 + 0x28);
                                            plVar7 = (longlong *)plVar12[2];
                                            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                                 *(undefined8 *)(lVar16 + 0x30);
                                            *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                                            if (plVar7 != (longlong *)0x0) {
                                              plVar12[2] = 0;
                                              *plVar7 = *plVar7 + -1;
                                              if (*plVar7 == 0) {
                                                (**(code **)(plVar7[1] + 0x30))();
                                              }
                                            }
                                            *plVar12 = *plVar12 + -1;
                                            if (*plVar12 == 0) {
                                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                                            }
                                            plVar12[0xf] = 0;
                                            pcVar19 = _Py_NoneStruct_exref;
                                            *(longlong *)_Py_NoneStruct_exref =
                                                 *(longlong *)_Py_NoneStruct_exref + 1;
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                                            }
                                            goto LAB_23e75c926;
                                          }
                                        }
                                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                        uVar18 = 0x3f2;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plVar14 = *(longlong **)(param_1 + 0x68);
                                        plVar13 = DAT_23ed6a4f8;
                                      }
                                    }
                                  }
                                }
                                goto joined_r0x00023e75c832;
                              }
                            }
                          }
                        }
                        puVar17 = *(undefined8 **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0x3e5;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar21 = 2;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = *(longlong **)(param_1 + 0x68);
                        plVar13 = DAT_23ed6a4f8;
                        goto joined_r0x00023e75c832;
                      }
                    }
                    puVar17 = *(undefined8 **)(param_1 + 0x60);
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0x3e4;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar21 = 2;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar14 = *(longlong **)(param_1 + 0x68);
                    plVar13 = DAT_23ed6a4f8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
joined_r0x00023e75c832:
  DAT_23ed6a4f8 = plVar13;
  if (plVar12 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar19 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar16 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar18;
    lVar16 = *(longlong *)(lVar16 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar16 = *(longlong *)(lVar16 + 0x2e8);
    lVar4 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar16 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar16;
    plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar16 + 8) = plVar13 + -2;
    plVar20 = plVar13;
  }
  else {
    plVar20 = plVar12;
    if ((longlong *)plVar12[3] != plVar7) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar13[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar18;
      pcVar19 = _PyRuntime_exref;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar13[-1];
      puVar6 = *(undefined8 **)(lVar16 + 8);
      *puVar6 = plVar13 + -2;
      plVar13[-2] = lVar16;
      plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar12;
      *(longlong **)(lVar16 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar12;
      plVar20 = plVar13;
      if (lVar4 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar7,"oooob",plVar1,plVar2,plVar3,plVar15,CONCAT44(uVar22,uVar21));
  if (_DAT_23eedadc8 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eedadc8 = (longlong *)0x0;
  }
  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar16 + 0x28);
  plVar7 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar12[0xf] = 0;
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,puVar17,plVar14,plVar20);
  return (code *)0x0;
}
