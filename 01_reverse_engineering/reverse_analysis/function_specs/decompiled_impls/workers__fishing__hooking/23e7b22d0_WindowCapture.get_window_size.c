/* ===== 23e7b22d0 workers.fishing.hooking:167 ===== */
/* ghidra_name=FUN_23e7b22d0 entry=23e7b22d0 size=8219 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7b22d0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  code *pcVar8;
  longlong *plVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong *plVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 in_stack_fffffffffffffea8;
  longlong *local_e0;
  longlong *local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  undefined1 local_98 [16];
  longlong *local_88;
  longlong *local_78;
  code *pcStack_70;
  longlong *local_68;
  
  pcVar8 = _Py_NoneStruct_exref;
  plVar5 = _DAT_23eedaad0;
  plVar12 = _DAT_23eed7bc8;
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  plVar1 = (longlong *)*param_3;
  pcVar2 = (code *)param_3[1];
  pcVar3 = (code *)param_3[2];
  plVar4 = (longlong *)param_3[3];
  local_88 = (longlong *)0x0;
  local_98._0_8_ = 0;
  local_98._8_8_ = 0;
  if ((pcVar2 == _Py_NoneStruct_exref) || (pcVar3 == _Py_NoneStruct_exref)) {
    *_DAT_23eed7bc8 = *_DAT_23eed7bc8 + 1;
    goto LAB_23e7b280b;
  }
  if (_DAT_23eedaad0 == (longlong *)0x0) {
LAB_23e7b235f:
    _DAT_23eedaad0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaac8,DAT_23eedab78,0x78);
  }
  else {
    lVar17 = *_DAT_23eedaad0;
    if (1 < lVar17) {
      *_DAT_23eedaad0 = lVar17 + -1;
      goto LAB_23e7b235f;
    }
    if (_DAT_23eedaad0[2] != 0) {
      *_DAT_23eedaad0 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      goto LAB_23e7b235f;
    }
  }
  plVar5 = _DAT_23eedaad0;
  plVar12 = _DAT_23eedaad0 + 9;
  lVar17 = *(longlong *)(param_1 + 0x38);
  lVar15 = *(longlong *)(lVar17 + 8);
  _DAT_23eedaad0[0xf] = lVar15;
  *(longlong **)(lVar17 + 8) = plVar12;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar12 = (longlong *)FUN_23a388310(plVar4);
  if (plVar12 == (longlong *)0x0) {
    uVar21 = *(undefined8 *)(param_1 + 0x60);
    uVar22 = *(undefined8 *)(param_1 + 0x68);
    plVar16 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else {
    local_c8 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
    if ((local_c8 == (longlong *)0x0) &&
       (local_c8 = (longlong *)FUN_23a3c1b70(param_1,local_98,0,4), local_c8 == (longlong *)0x0)) {
      local_e0 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
    }
    else {
      local_e0 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((local_e0 == (longlong *)0x0) &&
         (local_e0 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,4), local_e0 == (longlong *)0x0))
      {
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
      }
      else {
        plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
        if ((plVar13 == (longlong *)0x0) &&
           (plVar13 = (longlong *)FUN_23a3c1b70(param_1,local_98,2,4), plVar13 == (longlong *)0x0))
        {
          plVar14 = (longlong *)0x0;
        }
        else {
          plVar14 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if (((plVar14 != (longlong *)0x0) ||
              (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_98,3,4), plVar14 != (longlong *)0x0
              )) && (cVar10 = FUN_23a3884a0(param_1,local_98,plVar12,4), cVar10 != '\0')) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (*local_c8 == 0) {
              (**(code **)(local_c8[1] + 0x30))();
            }
            if (*local_e0 == 0) {
              (**(code **)(local_e0[1] + 0x30))();
            }
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            local_d0 = (longlong *)FUN_23e8c09e0(local_e0,plVar14);
            if (local_d0 == (longlong *)0x0) {
LAB_23e7b39d8:
              plVar19 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              plVar18 = (longlong *)0x0;
              local_b0 = (longlong *)0x0;
              uVar20 = 0xb0;
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_88 = *(longlong **)(param_1 + 0x70);
              local_c0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e7b2a0b;
            }
            local_c0 = (longlong *)FUN_23e8bc2f0(pcVar2,_DAT_23eed7a98);
            if (local_c0 == (longlong *)0x0) {
LAB_23e7b3a78:
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_88 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              lVar17 = *local_d0;
              *local_d0 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                (**(code **)(local_d0[1] + 0x30))(local_d0);
              }
              plVar19 = (longlong *)0x0;
              plVar18 = (longlong *)0x0;
              uVar20 = 0xb0;
              local_b8 = (longlong *)0x0;
              local_b0 = (longlong *)0x0;
              local_d0 = (longlong *)0x0;
              goto LAB_23e7b2a0b;
            }
            plVar12 = (longlong *)FUN_23a388650(param_1,local_c0,DAT_23ed6ccf0,0);
            lVar17 = *local_c0;
            *local_c0 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(local_c0[1] + 0x30))(local_c0);
            }
            if (plVar12 == (longlong *)0x0) {
LAB_23e7b3b10:
              plVar18 = (longlong *)0x0;
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_88 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              lVar17 = *local_d0;
              *local_d0 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                (**(code **)(local_d0[1] + 0x30))(local_d0);
              }
              local_b8 = (longlong *)0x0;
              plVar19 = (longlong *)0x0;
              uVar20 = 0xb0;
              local_b0 = (longlong *)0x0;
              local_d0 = (longlong *)0x0;
              local_c0 = (longlong *)0x0;
              goto LAB_23e7b2a0b;
            }
            iVar11 = FUN_23e97dbc0(local_d0,plVar12);
            lVar17 = *local_d0;
            *local_d0 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(local_d0[1] + 0x30))();
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (iVar11 == -1) {
LAB_23e7b3be0:
              plVar19 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              uVar20 = 0xb0;
              local_b0 = (longlong *)0x0;
              plVar18 = (longlong *)0x0;
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_88 = *(longlong **)(param_1 + 0x70);
              local_d0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_c0 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e7b2a0b;
            }
            if (iVar11 == 1) {
LAB_23e7b25e3:
              plVar12 = _DAT_23eed7bc8;
              local_c0 = (longlong *)0x0;
              *_DAT_23eed7bc8 = *_DAT_23eed7bc8 + 1;
LAB_23e7b25fa:
              lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar5 = *(longlong **)(lVar17 + 0x28);
              plVar16 = (longlong *)plVar5[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
              *(undefined4 *)(plVar5 + 8) = 0xffffffff;
              if (plVar16 != (longlong *)0x0) {
                plVar5[2] = 0;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
              }
              *plVar5 = *plVar5 + -1;
              if (*plVar5 == 0) {
                (**(code **)(plVar5[1] + 0x30))(plVar5);
              }
              local_a8 = (longlong *)0x0;
              plVar19 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              local_b0 = (longlong *)0x0;
              local_d0 = (longlong *)0x0;
              plVar5[0xf] = 0;
              plVar18 = (longlong *)0x0;
LAB_23e7b2689:
              lVar17 = *local_c8;
              *local_c8 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                (**(code **)(local_c8[1] + 0x30))(local_c8);
              }
              lVar17 = *local_e0;
              *local_e0 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                (**(code **)(local_e0[1] + 0x30))();
              }
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if ((local_c0 != (longlong *)0x0) &&
                 (lVar17 = *local_c0, *local_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
                (**(code **)(local_c0[1] + 0x30))(local_c0);
              }
              if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                (**(code **)(plVar18[1] + 0x30))(plVar18);
              }
              if ((local_d0 != (longlong *)0x0) &&
                 (lVar17 = *local_d0, *local_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
                (**(code **)(local_d0[1] + 0x30))();
              }
              if ((local_b0 != (longlong *)0x0) &&
                 (lVar17 = *local_b0, *local_b0 = lVar17 + -1, lVar17 + -1 == 0)) {
                (**(code **)(local_b0[1] + 0x30))(local_b0);
              }
              if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                (**(code **)(plVar19[1] + 0x30))(plVar19);
              }
              if ((local_b8 != (longlong *)0x0) &&
                 (lVar17 = *local_b8, *local_b8 = lVar17 + -1, lVar17 + -1 == 0)) {
                (**(code **)(local_b8[1] + 0x30))(local_b8);
              }
              if ((local_a8 != (longlong *)0x0) &&
                 (lVar17 = *local_a8, *local_a8 = lVar17 + -1, lVar17 + -1 == 0)) {
                (**(code **)(local_a8[1] + 0x30))(local_a8);
              }
LAB_23e7b280b:
              lVar17 = *plVar1;
              *plVar1 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              *(longlong *)pcVar2 = *(longlong *)pcVar2 + -1;
              if (*(longlong *)pcVar2 == 0) {
                (**(code **)(*(longlong *)(pcVar2 + 8) + 0x30))(pcVar2);
              }
              *(longlong *)pcVar3 = *(longlong *)pcVar3 + -1;
              if (*(longlong *)pcVar3 == 0) {
                (**(code **)(*(longlong *)(pcVar3 + 8) + 0x30))(pcVar3);
              }
              *plVar4 = *plVar4 + -1;
              if (*plVar4 != 0) {
                return plVar12;
              }
              (**(code **)(plVar4[1] + 0x30))(plVar4);
              return plVar12;
            }
            local_d0 = (longlong *)FUN_23e8c09e0(local_c8,plVar13);
            if (local_d0 == (longlong *)0x0) goto LAB_23e7b39d8;
            local_c0 = (longlong *)FUN_23e8bc2f0(pcVar2,_DAT_23eed7a98);
            if (local_c0 == (longlong *)0x0) goto LAB_23e7b3a78;
            plVar12 = (longlong *)FUN_23a388650(param_1,local_c0,DAT_23ed6ccf8,1);
            lVar17 = *local_c0;
            *local_c0 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(local_c0[1] + 0x30))(local_c0);
            }
            if (plVar12 == (longlong *)0x0) goto LAB_23e7b3b10;
            iVar11 = FUN_23e97dbc0(local_d0,plVar12);
            lVar17 = *local_d0;
            *local_d0 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(local_d0[1] + 0x30))();
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (iVar11 == -1) goto LAB_23e7b3be0;
            if (iVar11 == 1) goto LAB_23e7b25e3;
            local_c0 = (longlong *)FUN_23e8c09e0(local_e0,plVar14);
            if (local_c0 == (longlong *)0x0) {
LAB_23e7b3c7a:
              local_88 = *(longlong **)(param_1 + 0x70);
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              lVar15 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),local_e0,local_c0,pcVar8);
              lVar17 = *local_c0;
              *local_c0 = lVar17 + -1;
              if (lVar17 + -1 == 0) {
                (**(code **)(local_c0[1] + 0x30))(local_c0);
              }
              lVar17 = *(longlong *)(param_1 + 0x10);
              plVar12 = *(longlong **)(lVar17 + 0xe20);
              if (plVar12 == (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar6 = plVar12[3];
                *(int *)(lVar17 + 0xebc) = *(int *)(lVar17 + 0xebc) + -1;
                *(longlong *)(lVar17 + 0xe20) = lVar6;
                *plVar12 = 1;
              }
              pcVar8 = _PyRuntime_exref;
              plVar12[4] = 0;
              lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
              lVar6 = plVar12[-1];
              puVar7 = *(undefined8 **)(lVar17 + 8);
              *puVar7 = plVar12 + -2;
              plVar12[-2] = lVar17;
              plVar12[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar7;
              *(longlong **)(lVar17 + 8) = plVar12 + -2;
              plVar12[3] = lVar15;
              plVar16 = (longlong *)FUN_23e8c09e0(local_c8,plVar13);
              if (plVar16 != (longlong *)0x0) {
                lVar15 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),local_c8,plVar16);
                lVar17 = *plVar16;
                *plVar16 = lVar17 + -1;
                if (lVar17 + -1 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                plVar12[4] = lVar15;
                local_c0 = (longlong *)FUN_23a38cc10(param_1,pcVar2,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (local_c0 != (longlong *)0x0) {
                  plVar12 = (longlong *)FUN_23e8bc2f0(pcVar3,_DAT_23eed7a98);
                  if (plVar12 == (longlong *)0x0) {
LAB_23e7b3d3f:
                    local_88 = *(longlong **)(param_1 + 0x70);
                    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    local_b0 = (longlong *)FUN_23a388650(param_1,plVar12);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    if (local_b0 == (longlong *)0x0) {
LAB_23e7b3da0:
                      plVar19 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      plVar18 = (longlong *)0x0;
                      uVar20 = 0xb6;
                      local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_88 = *(longlong **)(param_1 + 0x70);
                      local_d0 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      goto LAB_23e7b2a0b;
                    }
                    plVar12 = (longlong *)FUN_23e8bc2f0(local_c0);
                    if (plVar12 != (longlong *)0x0) {
                      local_d0 = (longlong *)FUN_23a388650(param_1,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))();
                      }
                      if (local_d0 == (longlong *)0x0) {
LAB_23e7b3e56:
                        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        local_88 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        lVar17 = *local_b0;
                        *local_b0 = lVar17 + -1;
                        if (lVar17 + -1 == 0) {
                          FUN_23a334bc0();
                        }
                        plVar19 = (longlong *)0x0;
                        plVar18 = (longlong *)0x0;
                        local_b8 = (longlong *)0x0;
                        uVar20 = 0xb6;
                        local_b0 = (longlong *)0x0;
                        goto LAB_23e7b2a0b;
                      }
                      iVar11 = FUN_23e97dbc0(local_b0,local_d0);
                      lVar17 = *local_b0;
                      *local_b0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        (**(code **)(local_b0[1] + 0x30))(local_b0);
                      }
                      lVar17 = *local_d0;
                      *local_d0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        (**(code **)(local_d0[1] + 0x30))(local_d0);
                      }
                      if (iVar11 == -1) {
LAB_23e7b3ed7:
                        uVar20 = 0xb6;
                        local_b0 = (longlong *)0x0;
                        plVar19 = (longlong *)0x0;
                        local_d0 = (longlong *)0x0;
                        plVar18 = (longlong *)0x0;
                        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_88 = *(longlong **)(param_1 + 0x70);
                        local_b8 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        goto LAB_23e7b2a0b;
                      }
                      if (iVar11 == 1) {
LAB_23e7b3d2f:
                        plVar12 = _DAT_23eed7bc8;
                        *_DAT_23eed7bc8 = *_DAT_23eed7bc8 + 1;
                        goto LAB_23e7b25fa;
                      }
                      plVar12 = (longlong *)FUN_23e8bc2f0(pcVar3,_DAT_23eed7a98);
                      if (plVar12 == (longlong *)0x0) goto LAB_23e7b3d3f;
                      local_b0 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf8,1);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      if (local_b0 == (longlong *)0x0) goto LAB_23e7b3da0;
                      plVar12 = (longlong *)FUN_23e8bc2f0(local_c0);
                      if (plVar12 == (longlong *)0x0) goto LAB_23e7b3df2;
                      local_d0 = (longlong *)FUN_23a388650(param_1,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      if (local_d0 == (longlong *)0x0) goto LAB_23e7b3e56;
                      iVar11 = FUN_23e97dbc0(local_b0,local_d0);
                      lVar17 = *local_b0;
                      *local_b0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(local_b0);
                      }
                      lVar17 = *local_d0;
                      *local_d0 = lVar17 + -1;
                      if (lVar17 + -1 == 0) {
                        FUN_23a334bc0(local_d0);
                      }
                      if (iVar11 == -1) goto LAB_23e7b3ed7;
                      if (iVar11 == 1) goto LAB_23e7b3d2f;
                      lVar17 = FUN_23e8df050();
                      if (lVar17 == 0) {
                        FUN_23e915740(param_1,local_98,_DAT_23eed7aa0);
                        plVar18 = (longlong *)0x0;
                      }
                      else {
                        plVar12 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eed7bd0);
                        if (plVar12 == (longlong *)0x0) {
                          plVar19 = (longlong *)0x0;
                          local_b8 = (longlong *)0x0;
                          plVar18 = (longlong *)0x0;
                          uVar20 = 0xba;
                          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          local_88 = *(longlong **)(param_1 + 0x70);
                          local_d0 = (longlong *)0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          local_b0 = (longlong *)0x0;
                          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          goto LAB_23e7b2a0b;
                        }
                        lVar17 = FUN_23e8df050();
                        if (lVar17 == 0) {
                          FUN_23e915740(param_1,local_98,_DAT_23eed7aa0);
                          lVar17 = *plVar12;
                          *plVar12 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          plVar18 = (longlong *)0x0;
                        }
                        else {
                          plVar16 = (longlong *)FUN_23e8bc2f0(lVar17);
                          if (plVar16 == (longlong *)0x0) {
                            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            local_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar17 = *plVar12;
                            *plVar12 = lVar17 + -1;
                            if (lVar17 + -1 == 0) {
                              FUN_23a334bc0(plVar12);
                            }
                            plVar19 = (longlong *)0x0;
                            plVar18 = (longlong *)0x0;
                            local_b0 = (longlong *)0x0;
                            uVar20 = 0xba;
                            local_b8 = (longlong *)0x0;
                            local_d0 = (longlong *)0x0;
                            goto LAB_23e7b2a0b;
                          }
                          *(undefined4 *)(plVar5 + 5) = 0xba;
                          local_78 = local_c0;
                          pcStack_70 = pcVar3;
                          local_68 = plVar16;
                          plVar18 = (longlong *)FUN_23e956150(param_1,plVar12,&local_78);
                          lVar17 = *plVar12;
                          *plVar12 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          lVar17 = *plVar16;
                          *plVar16 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            FUN_23a334bc0(plVar16);
                          }
                          if (plVar18 != (longlong *)0x0) {
                            lVar17 = FUN_23e8df050();
                            if (lVar17 == 0) {
                              FUN_23e915740(param_1,local_98,_DAT_23eed7aa0);
                              plVar12 = local_88;
                              uVar21 = local_98._0_8_;
                              uVar22 = local_98._8_8_;
                            }
                            else {
                              *(undefined4 *)(plVar5 + 5) = 0xbb;
                              plVar12 = (longlong *)
                                        FUN_23e915840(param_1,lVar17,_DAT_23eed7be0,plVar18);
                              if (plVar12 != (longlong *)0x0) {
                                plVar16 = (longlong *)FUN_23a388310(plVar12);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  FUN_23a334bc0(plVar12);
                                }
                                if (plVar16 != (longlong *)0x0) {
                                  local_d0 = (longlong *)
                                             FUN_23a3c1d30(param_1,local_98,plVar16,0,
                                                           CONCAT44(uVar20,4));
                                  if (local_d0 == (longlong *)0x0) {
                                    plVar19 = (longlong *)0x0;
                                    local_b8 = (longlong *)0x0;
                                    local_b0 = (longlong *)0x0;
                                  }
                                  else {
                                    local_b0 = (longlong *)
                                               FUN_23a3c1d30(param_1,local_98,plVar16,1,4);
                                    if (local_b0 == (longlong *)0x0) {
                                      plVar19 = (longlong *)0x0;
                                      local_b8 = (longlong *)0x0;
                                    }
                                    else {
                                      plVar19 = (longlong *)
                                                FUN_23a3c1d30(param_1,local_98,plVar16,2,4);
                                      if (plVar19 == (longlong *)0x0) {
                                        local_b8 = (longlong *)0x0;
                                      }
                                      else {
                                        local_b8 = (longlong *)
                                                   FUN_23a3c1d30(param_1,local_98,plVar16,3,4);
                                        if ((local_b8 != (longlong *)0x0) &&
                                           (cVar10 = FUN_23a3884a0(param_1,local_98), cVar10 != '\0'
                                           )) {
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            FUN_23a334bc0(plVar16);
                                          }
                                          if (*local_d0 == 0) {
                                            FUN_23a334bc0(local_d0);
                                          }
                                          if (*local_b0 == 0) {
                                            FUN_23a334bc0(local_b0);
                                          }
                                          if (*plVar19 == 0) {
                                            FUN_23a334bc0(plVar19);
                                          }
                                          if (*local_b8 == 0) {
                                            FUN_23a334bc0(local_b8);
                                          }
                                          lVar17 = FUN_23e8dec60();
                                          if (lVar17 == 0) {
                                            FUN_23e915740(param_1,local_98,_DAT_23eed7be8);
                                            uVar20 = 0xbe;
                                            goto LAB_23e7b2a0b;
                                          }
                                          local_a8 = (longlong *)FUN_23e8d1240(local_b0,lVar17);
                                          if (local_a8 == (longlong *)0x0) {
                                            uVar20 = 0xbe;
                                            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            local_88 = *(longlong **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            goto LAB_23e7b2a0b;
                                          }
                                          FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                          plVar12 = (longlong *)
                                                    FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2)
                                          ;
                                          *local_b0 = *local_b0 + 1;
                                          plVar12[3] = (longlong)local_b0;
                                          *local_a8 = *local_a8 + 1;
                                          plVar12[4] = (longlong)local_a8;
                                          goto LAB_23e7b2689;
                                        }
                                      }
                                    }
                                  }
                                  plVar12 = local_88;
                                  uVar22 = local_98._8_8_;
                                  uVar21 = local_98._0_8_;
                                  local_98 = (undefined1  [16])0x0;
                                  local_88 = (longlong *)0x0;
                                  *plVar16 = *plVar16 + -1;
                                  if (*plVar16 == 0) {
                                    FUN_23a334bc0(plVar16);
                                  }
                                  local_88 = (longlong *)0x0;
                                  local_98._0_8_ = 0;
                                  local_98._8_8_ = 0;
                                  if ((local_d0 != (longlong *)0x0) &&
                                     (lVar17 = *local_d0, *local_d0 = lVar17 + -1, lVar17 + -1 == 0)
                                     ) {
                                    FUN_23a334bc0(local_d0);
                                  }
                                  if ((local_b0 != (longlong *)0x0) &&
                                     (lVar17 = *local_b0, *local_b0 = lVar17 + -1, lVar17 + -1 == 0)
                                     ) {
                                    FUN_23a334bc0(local_b0);
                                  }
                                  if ((plVar19 != (longlong *)0x0) &&
                                     (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                                    FUN_23a334bc0(plVar19);
                                  }
                                  if ((local_b8 != (longlong *)0x0) &&
                                     (lVar17 = *local_b8, *local_b8 = lVar17 + -1, lVar17 + -1 == 0)
                                     ) {
                                    FUN_23a334bc0(local_b8);
                                  }
                                  goto LAB_23e7b4139;
                                }
                              }
                              uVar21 = *(undefined8 *)(param_1 + 0x60);
                              plVar12 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              uVar22 = *(undefined8 *)(param_1 + 0x68);
                            }
LAB_23e7b4139:
                            plVar19 = (longlong *)0x0;
                            local_b8 = (longlong *)0x0;
                            uVar20 = 0xbb;
                            local_b0 = (longlong *)0x0;
                            local_d0 = (longlong *)0x0;
                            local_88 = plVar12;
                            local_98._0_8_ = uVar21;
                            local_98._8_8_ = uVar22;
                            goto LAB_23e7b2a0b;
                          }
                          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          local_88 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                      }
                      plVar19 = (longlong *)0x0;
                      uVar20 = 0xba;
                      local_b8 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      goto LAB_23e7b2a0b;
                    }
LAB_23e7b3df2:
                    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_88 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    lVar17 = *local_b0;
                    *local_b0 = lVar17 + -1;
                    if (lVar17 + -1 == 0) {
                      FUN_23a334bc0(local_b0);
                    }
                  }
                  plVar18 = (longlong *)0x0;
                  local_b8 = (longlong *)0x0;
                  plVar19 = (longlong *)0x0;
                  uVar20 = 0xb6;
                  local_b0 = (longlong *)0x0;
                  local_d0 = (longlong *)0x0;
                  goto LAB_23e7b2a0b;
                }
                goto LAB_23e7b3c7a;
              }
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              local_88 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              local_c0 = (longlong *)0x0;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
            }
            plVar19 = (longlong *)0x0;
            plVar18 = (longlong *)0x0;
            uVar20 = 0xb3;
            local_b8 = (longlong *)0x0;
            local_b0 = (longlong *)0x0;
            local_d0 = (longlong *)0x0;
            goto LAB_23e7b2a0b;
          }
        }
      }
    }
    plVar16 = local_88;
    uVar22 = local_98._8_8_;
    uVar21 = local_98._0_8_;
    local_88 = (longlong *)0x0;
    local_98 = (undefined1  [16])0x0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    local_88 = (longlong *)0x0;
    local_98._0_8_ = 0;
    local_98._8_8_ = 0;
    if ((local_c8 != (longlong *)0x0) &&
       (lVar17 = *local_c8, *local_c8 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(local_c8[1] + 0x30))(local_c8);
    }
    if ((local_e0 != (longlong *)0x0) &&
       (lVar17 = *local_e0, *local_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(local_e0[1] + 0x30))();
    }
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
  }
  plVar19 = (longlong *)0x0;
  plVar18 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  uVar20 = 0xad;
  local_b0 = (longlong *)0x0;
  local_d0 = (longlong *)0x0;
  local_c0 = (longlong *)0x0;
  local_e0 = (longlong *)0x0;
  local_c8 = (longlong *)0x0;
  local_88 = plVar16;
  local_98._0_8_ = uVar21;
  local_98._8_8_ = uVar22;
LAB_23e7b2a0b:
  plVar16 = local_88;
  plVar12 = DAT_23ed6a4f8;
  if (local_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar20;
    pcVar8 = _PyRuntime_exref;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
    lVar15 = plVar12[-1];
    puVar7 = *(undefined8 **)(lVar17 + 8);
    *puVar7 = plVar12 + -2;
    plVar12[-2] = lVar17;
    plVar12[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar17 + 8) = plVar12 + -2;
    plVar16 = plVar12;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))(local_88);
    }
  }
  else if ((longlong *)local_88[3] != plVar5) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar12[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar20;
    pcVar8 = _PyRuntime_exref;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
    lVar15 = plVar12[-1];
    puVar7 = *(undefined8 **)(lVar17 + 8);
    *puVar7 = plVar12 + -2;
    plVar12[-2] = lVar17;
    plVar12[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar17 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar16;
    *plVar16 = *plVar16 + 1;
    plVar16 = plVar12;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))();
    }
  }
  local_88 = plVar16;
  FUN_23e8bba40(plVar5,"ooooooooooooooo",plVar1,pcVar2,pcVar3,plVar4,local_c8,local_e0,plVar13,
                plVar14,local_c0,plVar18,local_d0,local_b0,plVar19,local_b8,0);
  if (_DAT_23eedaad0 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedaad0 = (longlong *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar17 + 0x28);
  plVar5 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar5 = local_88;
  uVar22 = local_98._8_8_;
  uVar21 = local_98._0_8_;
  plVar12[0xf] = 0;
  local_98 = (undefined1  [16])0x0;
  local_88 = (longlong *)0x0;
  if ((local_c8 != (longlong *)0x0) &&
     (lVar17 = *local_c8, *local_c8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(local_c8[1] + 0x30))(local_c8);
  }
  if ((local_e0 != (longlong *)0x0) &&
     (lVar17 = *local_e0, *local_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar17 = *local_c0, *local_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((local_d0 != (longlong *)0x0) &&
     (lVar17 = *local_d0, *local_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(local_d0[1] + 0x30))(local_d0);
  }
  if ((local_b0 != (longlong *)0x0) &&
     (lVar17 = *local_b0, *local_b0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(local_b0[1] + 0x30))(local_b0);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar17 = *local_b8, *local_b8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  local_98 = CONCAT88(uVar22,uVar21);
  lVar17 = *plVar1;
  *plVar1 = lVar17 + -1;
  local_88 = plVar5;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *(longlong *)pcVar2 = *(longlong *)pcVar2 + -1;
  if (*(longlong *)pcVar2 == 0) {
    (**(code **)(*(longlong *)(pcVar2 + 8) + 0x30))(pcVar2);
  }
  *(longlong *)pcVar3 = *(longlong *)pcVar3 + -1;
  if (*(longlong *)pcVar3 == 0) {
    (**(code **)(*(longlong *)(pcVar3 + 8) + 0x30))(pcVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88);
  return (longlong *)0x0;
}
