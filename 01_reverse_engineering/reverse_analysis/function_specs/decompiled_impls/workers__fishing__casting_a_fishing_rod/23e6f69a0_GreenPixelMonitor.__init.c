/* ===== 23e6f69a0 workers.fishing.casting_a_fishin:127 ===== */
/* ghidra_name=FUN_23e6f69a0 entry=23e6f69a0 size=3218 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e6f69a0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  code *pcVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  longlong *plStack_90;
  longlong *plStack_88;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar13 = _DAT_23eedb200;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23eedb200 == (longlong *)0x0) {
LAB_23e6f69f5:
    _DAT_23eedb200 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb1f8,DAT_23eedb268,0x10);
  }
  else {
    lVar12 = *_DAT_23eedb200;
    if (1 < lVar12) {
      *_DAT_23eedb200 = lVar12 + -1;
      goto LAB_23e6f69f5;
    }
    if (_DAT_23eedb200[2] != 0) {
      *_DAT_23eedb200 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      goto LAB_23e6f69f5;
    }
  }
  plVar5 = _DAT_23eedb200;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar13 = _DAT_23eedb200 + 9;
  lVar3 = *(longlong *)(lVar12 + 8);
  _DAT_23eedb200[0xf] = lVar3;
  *(longlong **)(lVar12 + 8) = plVar13;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar13 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar13;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar15 = _DAT_23eeda4a0;
  *(undefined4 *)(plVar5 + 8) = 0;
  cVar8 = FUN_23e8d9ac0(plVar1,uVar15,plVar2);
  if (cVar8 == '\0') {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar13 = *(longlong **)(param_1 + 0x70);
    uVar14 = 0x80;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = DAT_23ed6a4f8;
    goto joined_r0x00023e6f71dc;
  }
  plVar9 = (longlong *)FUN_23a388310(plVar2);
  if (plVar9 == (longlong *)0x0) {
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    uVar16 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    plVar10 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
    if ((plVar10 == (longlong *)0x0) &&
       (plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,4), plVar10 == (longlong *)0x0)) {
      plStack_88 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
LAB_23e6f6eb0:
      plVar13 = plStack_68;
      uVar15 = auStack_78._0_8_;
      uVar16 = auStack_78._8_8_;
      plStack_68 = (longlong *)0x0;
      auStack_78 = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      plStack_68 = (longlong *)0x0;
      auStack_78 = (undefined1  [16])0x0;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
LAB_23e6f7120:
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plStack_90 != (longlong *)0x0) {
LAB_23e6f6f02:
        lVar12 = *plStack_90;
        *plStack_90 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
LAB_23e6f7170:
          (**(code **)(plStack_90[1] + 0x30))();
        }
      }
      if (plVar11 != (longlong *)0x0) {
LAB_23e6f6f21:
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
LAB_23e6f6f28:
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
      }
      if (plStack_88 == (longlong *)0x0) goto LAB_23e6f6f5a;
    }
    else {
      plStack_90 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
      if ((plStack_90 == (longlong *)0x0) &&
         (plStack_90 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,4),
         plStack_90 == (longlong *)0x0)) {
        plStack_88 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        goto LAB_23e6f6eb0;
      }
      plVar11 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
      if ((plVar11 == (longlong *)0x0) &&
         (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,2,4), plVar11 == (longlong *)0x0))
      {
        plStack_88 = (longlong *)0x0;
        goto LAB_23e6f6eb0;
      }
      plStack_88 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
      if (((plStack_88 == (longlong *)0x0) &&
          (plStack_88 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,3,4),
          plStack_88 == (longlong *)0x0)) ||
         (cVar8 = FUN_23a3884a0(param_1,auStack_78,plVar9,4), cVar8 == '\0')) goto LAB_23e6f6eb0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4a8,plVar10);
      lVar12 = *plVar10 + -1;
      if (cVar8 == '\0') {
        uVar15 = *(undefined8 *)(param_1 + 0x60);
        uVar16 = *(undefined8 *)(param_1 + 0x68);
        plVar13 = *(longlong **)(param_1 + 0x70);
        plStack_68 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_78 = (undefined1  [16])0x0;
        *plVar10 = lVar12;
        if (lVar12 == 0) goto LAB_23e6f7120;
        goto LAB_23e6f6f02;
      }
      *plVar10 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4b0,plStack_90);
      lVar12 = *plStack_90 + -1;
      if (cVar8 == '\0') {
        uVar15 = *(undefined8 *)(param_1 + 0x60);
        uVar16 = *(undefined8 *)(param_1 + 0x68);
        plStack_68 = (longlong *)0x0;
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        auStack_78 = (undefined1  [16])0x0;
        *plStack_90 = lVar12;
        if (lVar12 == 0) goto LAB_23e6f7170;
        goto LAB_23e6f6f21;
      }
      *plStack_90 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plStack_90[1] + 0x30))();
      }
      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4b8,plVar11);
      lVar12 = *plVar11 + -1;
      if (cVar8 == '\0') {
        uVar15 = *(undefined8 *)(param_1 + 0x60);
        uVar16 = *(undefined8 *)(param_1 + 0x68);
        plVar13 = *(longlong **)(param_1 + 0x70);
        plStack_68 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_78 = (undefined1  [16])0x0;
        *plVar11 = lVar12;
        if (lVar12 != 0) goto LAB_23e6f6f3a;
        goto LAB_23e6f6f28;
      }
      *plVar11 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4c0,plStack_88);
      if (cVar8 != '\0') {
        lVar12 = *plStack_88;
        *plStack_88 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plStack_88[1] + 0x30))(plStack_88);
        }
        uVar15 = DAT_23ed6cd08;
        lVar12 = FUN_23e8e1b00();
        if (lVar12 == 0) {
          uVar14 = 0x82;
          FUN_23e915740(param_1,auStack_78,DAT_23eeda4c8);
          plVar13 = plStack_68;
          plVar9 = DAT_23ed6a4f8;
        }
        else {
          cVar8 = FUN_23e8d9ac0(lVar12,_DAT_23eeda4d0,uVar15);
          if (cVar8 == '\0') {
            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar13 = *(longlong **)(param_1 + 0x70);
            uVar14 = 0x82;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = DAT_23ed6a4f8;
          }
          else {
            lVar12 = FUN_23e8e1b00();
            pcVar6 = _Py_FalseStruct_exref;
            if (lVar12 == 0) {
              uVar14 = 0x83;
              FUN_23e915740(param_1,auStack_78,DAT_23eeda4c8);
              plVar13 = plStack_68;
              plVar9 = DAT_23ed6a4f8;
            }
            else {
              cVar8 = FUN_23e8d9ac0(lVar12,_DAT_23eeda4d8,_Py_FalseStruct_exref);
              if (cVar8 == '\0') {
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plVar13 = *(longlong **)(param_1 + 0x70);
                uVar14 = 0x83;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar9 = DAT_23ed6a4f8;
              }
              else {
                plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda4e0);
                if (plVar13 != (longlong *)0x0) {
                  cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4e8,plVar13);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  pcVar7 = _Py_NoneStruct_exref;
                  if (cVar8 != '\0') {
                    cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4f0,_Py_NoneStruct_exref);
                    if (cVar8 == '\0') {
                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      uVar14 = 0x86;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar9 = DAT_23ed6a4f8;
                    }
                    else {
                      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda4f8,DAT_23ed6ccf0);
                      if (cVar8 == '\0') {
                        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        plVar13 = *(longlong **)(param_1 + 0x70);
                        uVar14 = 0x87;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar9 = DAT_23ed6a4f8;
                      }
                      else {
                        cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda500,DAT_23ed6cd08);
                        if (cVar8 == '\0') {
                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                          plVar13 = *(longlong **)(param_1 + 0x70);
                          uVar14 = 0x88;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar9 = DAT_23ed6a4f8;
                        }
                        else {
                          cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda508,DAT_23ed6cd08);
                          if (cVar8 == '\0') {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plVar13 = *(longlong **)(param_1 + 0x70);
                            uVar14 = 0x89;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar9 = DAT_23ed6a4f8;
                          }
                          else {
                            cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda510,pcVar6);
                            if (cVar8 == '\0') {
                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plVar13 = *(longlong **)(param_1 + 0x70);
                              uVar14 = 0x8a;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar9 = DAT_23ed6a4f8;
                            }
                            else {
                              cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda518,DAT_23ed6ccf0);
                              if (cVar8 == '\0') {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plVar13 = *(longlong **)(param_1 + 0x70);
                                uVar14 = 0x8c;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar9 = DAT_23ed6a4f8;
                              }
                              else {
                                lVar12 = FUN_23e8e19b0();
                                if (lVar12 == 0) {
                                  uVar14 = 0x8d;
                                  FUN_23e915740(param_1,auStack_78,DAT_23eeda520);
                                  plVar13 = plStack_68;
                                  plVar9 = DAT_23ed6a4f8;
                                }
                                else {
                                  *(undefined4 *)(plVar5 + 5) = 0x8d;
                                  plVar13 = (longlong *)FUN_23e91bfe0(param_1);
                                  if (plVar13 != (longlong *)0x0) {
                                    cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda528,plVar13);
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    if (cVar8 != '\0') {
                                      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eeda530,DAT_23ed6ccf0);
                                      if (cVar8 != '\0') {
                                        FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                        *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                                        *plVar1 = *plVar1 + -1;
                                        if (*plVar1 == 0) {
                                          FUN_23a334bc0(plVar1);
                                        }
                                        *plVar2 = *plVar2 + -1;
                                        if (*plVar2 != 0) {
                                          return pcVar7;
                                        }
                                        FUN_23a334bc0(plVar2);
                                        return pcVar7;
                                      }
                                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                      plVar13 = *(longlong **)(param_1 + 0x70);
                                      uVar14 = 0x8e;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plVar9 = DAT_23ed6a4f8;
                                      goto joined_r0x00023e6f71dc;
                                    }
                                  }
                                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  plVar13 = *(longlong **)(param_1 + 0x70);
                                  uVar14 = 0x8d;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar9 = DAT_23ed6a4f8;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    goto joined_r0x00023e6f71dc;
                  }
                }
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plVar13 = *(longlong **)(param_1 + 0x70);
                uVar14 = 0x85;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar9 = DAT_23ed6a4f8;
              }
            }
          }
        }
        goto joined_r0x00023e6f71dc;
      }
      uVar15 = *(undefined8 *)(param_1 + 0x60);
      uVar16 = *(undefined8 *)(param_1 + 0x68);
      plVar13 = *(longlong **)(param_1 + 0x70);
      plStack_68 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      auStack_78 = (undefined1  [16])0x0;
    }
LAB_23e6f6f3a:
    lVar12 = *plStack_88;
    *plStack_88 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
LAB_23e6f6f5a:
  uVar14 = 0x81;
  auStack_78._8_8_ = uVar16;
  auStack_78._0_8_ = uVar15;
  plVar9 = DAT_23ed6a4f8;
joined_r0x00023e6f71dc:
  DAT_23ed6a4f8 = plVar9;
  plStack_68 = plVar13;
  if (plVar13 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar14;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar12;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar9 + -2;
    plVar13 = plVar9;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else if ((longlong *)plVar13[3] != plVar5) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar14;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar3 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar12;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar13;
    *plVar13 = *plVar13 + 1;
    plVar13 = plVar9;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
  plStack_68 = plVar13;
  FUN_23e8bba40(plVar5,&DAT_23ec5dd15,plVar1,plVar2);
  if (_DAT_23eedb200 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedb200 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar12 + 0x28);
  plVar5 = (longlong *)plVar13[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar13[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68);
  return (code *)0x0;
}
