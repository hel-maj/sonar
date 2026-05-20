/* ===== 23e773110 workers.fishing.fishing_bot:FishingBot._wait_for_start_phase ===== */
/* ghidra_name=FUN_23e773110 entry=23e773110 size=21874 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e773110(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  undefined4 uVar17;
  longlong *in_R10;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 in_stack_fffffffffffffde8;
  longlong *plStack_170;
  code *pcStack_168;
  longlong *plStack_160;
  longlong *plStack_158;
  longlong *plStack_150;
  longlong *plStack_148;
  code *pcStack_140;
  code *pcStack_138;
  longlong *plStack_130;
  code *pcStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  code *pcStack_f8;
  longlong *plStack_f0;
  undefined1 auStack_d8 [16];
  longlong *plStack_c8;
  undefined8 uStack_b8;
  code *pcStack_b0;
  code *pcStack_a8;
  code *pcStack_a0;
  undefined8 uStack_98;
  code *pcStack_88;
  code *pcStack_80;
  code *pcStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  plVar8 = _DAT_23eedad70;
  uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffffde8 >> 0x20);
  plVar1 = (longlong *)*param_3;
  plStack_c8 = (longlong *)0x0;
  auStack_d8 = (undefined1  [16])0x0;
  if (_DAT_23eedad70 == (longlong *)0x0) {
LAB_23e77316d:
    _DAT_23eedad70 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf60,DAT_23eedaeb8,0xa8);
  }
  else {
    lVar10 = *_DAT_23eedad70;
    if (1 < lVar10) {
      *_DAT_23eedad70 = lVar10 + -1;
      goto LAB_23e77316d;
    }
    if (_DAT_23eedad70[2] != 0) {
      *_DAT_23eedad70 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e77316d;
    }
  }
  plVar3 = _DAT_23eedad70;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedad70 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eedad70[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar18 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
  if (plVar8 == (longlong *)0x0) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    pcVar15 = (code *)0x0;
    pcVar16 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar17 = 0x57f;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    pcStack_140 = (code *)0x0;
    pcStack_138 = (code *)0x0;
    pcStack_168 = (code *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    goto LAB_23e7740e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x57f;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eed8d38);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (plVar9 == (longlong *)0x0) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    pcVar15 = (code *)0x0;
    pcVar16 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar17 = 0x57f;
    plStack_100 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    pcStack_140 = (code *)0x0;
    pcStack_138 = (code *)0x0;
    pcStack_168 = (code *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e7740e0;
  }
  iVar7 = FUN_23a35f020(plVar9);
  lVar10 = *plVar9 + -1;
  if (iVar7 == -1) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    uVar17 = 0x57f;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar9 = lVar10;
    if (lVar10 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar17 = 0x57f;
    }
LAB_23e77401f:
    plStack_100 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    pcVar15 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    pcVar16 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    pcStack_140 = (code *)0x0;
    pcStack_138 = (code *)0x0;
    pcStack_168 = (code *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    goto LAB_23e7740e0;
  }
  *plVar9 = lVar10;
  if (lVar10 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (iVar7 == 0) {
    cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_TrueStruct_exref);
    if (cVar6 == '\0') {
      plStack_c8 = *(longlong **)(param_1 + 0x70);
      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      uVar17 = 0x581;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e77401f;
    }
    lVar10 = FUN_23e8e0e20();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,auStack_d8,DAT_23eed8988);
    }
    else {
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eed95e0);
      if (plVar8 != (longlong *)0x0) {
        cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (cVar6 == '\0') {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          uVar17 = 0x582;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e77401f;
        }
        *(undefined4 *)(plVar3 + 5) = 0x583;
        plVar8 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8b40);
        if (plVar8 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar9 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          uVar17 = 0x583;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          pcStack_140 = (code *)0x0;
          pcStack_138 = (code *)0x0;
          pcStack_168 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e7740e0;
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *(undefined4 *)(plVar3 + 5) = 0x586;
        plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed8d78);
        if (plVar8 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar9 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          uVar17 = 0x586;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          pcStack_140 = (code *)0x0;
          pcStack_138 = (code *)0x0;
          pcStack_168 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7740e0;
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
        pcVar15 = DAT_23eed8db0;
        lVar10 = DAT_23ed6cce8;
        if (plVar9 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar9 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          uVar17 = 0x587;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          pcStack_140 = (code *)0x0;
          pcStack_138 = (code *)0x0;
          pcStack_168 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_148 = (longlong *)0x0;
          goto LAB_23e7740e0;
        }
        lVar2 = *(longlong *)(param_1 + 0x10);
        iVar7 = *(int *)(lVar2 + 0x1410);
        plVar11 = *(longlong **)(DAT_23ed6cce8 + 0x20);
        *plVar11 = *plVar11 + 1;
        if (iVar7 == 0) {
          pcVar16 = (code *)FUN_23a33a530(PyDict_Type_exref);
          plVar11 = *(longlong **)(lVar10 + 0x20);
        }
        else {
          iVar7 = iVar7 + -1;
          *(int *)(lVar2 + 0x1410) = iVar7;
          pcVar16 = *(code **)(lVar2 + 0x1190 + (longlong)iVar7 * 8);
          *(longlong *)pcVar16 = 1;
        }
        lVar10 = *(longlong *)(lVar10 + 0x28);
        *(longlong *)(pcVar16 + 0x10) = 0;
        *(longlong **)(pcVar16 + 0x20) = plVar11;
        *(longlong *)(pcVar16 + 0x28) = lVar10;
        *(longlong *)(pcVar16 + 0x18) = 1;
        *(undefined4 *)(plVar3 + 5) = 0x587;
        pcStack_88 = pcVar15;
        pcStack_80 = pcVar16;
        plVar11 = (longlong *)FUN_23e94ed00(param_1,plVar9,&pcStack_88);
        lVar10 = *plVar9;
        *plVar9 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
        if (*(longlong *)pcVar16 == 0) {
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
        }
        if (plVar11 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar9 = (longlong *)0x0;
          uVar17 = 0x587;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          pcStack_140 = (code *)0x0;
          pcStack_138 = (code *)0x0;
          pcStack_168 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7740e0;
        }
        iVar7 = PySequence_Contains(plVar11,DAT_23eed8dc0);
        lVar10 = _DAT_23eed95f0;
        if (iVar7 == -1) {
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          uVar17 = 0x588;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e7751e3;
        }
        if (iVar7 == 1) {
          *(undefined4 *)(plVar3 + 5) = 0x589;
          plVar9 = (longlong *)
                   FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar10 + 0x18));
          if (plVar9 == (longlong *)0x0) {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            pcVar15 = (code *)0x0;
            pcVar16 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar9 = (longlong *)0x0;
            uVar17 = 0x589;
            plStack_100 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            plStack_158 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            pcStack_140 = (code *)0x0;
            pcStack_138 = (code *)0x0;
            pcStack_168 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_150 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plStack_148 = (longlong *)0x0;
            goto LAB_23e7740e0;
          }
          lVar10 = *plVar9;
          *plVar9 = lVar10 + -1;
          if (lVar10 + -1 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_FalseStruct_exref);
          if (cVar6 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            uVar17 = 0x58a;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7751e3:
            plStack_100 = (longlong *)0x0;
            pcVar15 = (code *)0x0;
            pcVar16 = (code *)0x0;
            plVar9 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            plStack_158 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            pcStack_140 = (code *)0x0;
            pcStack_138 = (code *)0x0;
            pcStack_168 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_150 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_148 = (longlong *)0x0;
          }
          else {
            lVar10 = FUN_23e8e0e20();
            if (lVar10 == 0) {
              FUN_23e915740(param_1,auStack_d8,DAT_23eed8988);
            }
            else {
              plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eed8990);
              if (plVar9 != (longlong *)0x0) {
                cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar9);
                lVar10 = *plVar9;
                *plVar9 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (cVar6 != '\0') {
                  lVar10 = *(longlong *)_Py_NoneStruct_exref;
                  goto LAB_23e773290;
                }
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                uVar17 = 0x58b;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7751e3;
              }
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            plStack_148 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            pcVar15 = (code *)0x0;
            pcVar16 = (code *)0x0;
            plVar9 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            uVar17 = 0x58b;
            plStack_160 = (longlong *)0x0;
            plStack_158 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            pcStack_140 = (code *)0x0;
            pcStack_138 = (code *)0x0;
            pcStack_168 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_150 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
          }
          goto LAB_23e7740e0;
        }
        *(undefined4 *)(plVar3 + 5) = 0x58f;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed95c0);
        if (plVar9 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          pcVar15 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar9 = (longlong *)0x0;
          uVar17 = 0x58f;
          plStack_100 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          pcStack_140 = (code *)0x0;
          pcStack_138 = (code *)0x0;
          pcStack_168 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_148 = (longlong *)0x0;
          goto LAB_23e7740e0;
        }
        lVar10 = *plVar9;
        *plVar9 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        lVar10 = FUN_23e8e0a50();
        if (lVar10 == 0) {
          FUN_23e915740(param_1,auStack_d8,_DAT_23eed8d18);
          plStack_148 = (longlong *)0x0;
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0x592;
          plStack_148 = (longlong *)FUN_23e94bb80(param_1,lVar10);
          if (plStack_148 != (longlong *)0x0) {
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x594;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_120 = (longlong *)0x0;
              goto LAB_23e7740e0;
            }
            iVar7 = FUN_23e913250(plVar9,DAT_23eed90d8);
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (iVar7 == -1) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x594;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            if (iVar7 == 1) {
              plStack_120 = (longlong *)FUN_23e8c6f80(plStack_148,_DAT_23eed95f8);
              if (plStack_120 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                plStack_100 = (longlong *)0x0;
                pcVar16 = (code *)0x0;
                uVar17 = 0x595;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar15 = (code *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_138 = (code *)0x0;
                pcStack_168 = (code *)0x0;
                pcStack_128 = (code *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_150 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7740e0;
              }
            }
            else {
              plStack_120 = (longlong *)FUN_23e8c6f80(plStack_148,_DAT_23eed9600);
              if (plStack_120 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                plStack_100 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar17 = 0x597;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_138 = (code *)0x0;
                pcStack_168 = (code *)0x0;
                pcStack_128 = (code *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_150 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7740e0;
              }
            }
            pcStack_f8 = _Py_NoneStruct_exref;
            uStack_b8 = _DAT_23eed9608;
            *(undefined4 *)(plVar3 + 5) = 0x599;
            pcStack_b0 = DAT_23eed8950;
            uStack_98 = DAT_23ed6ccf0;
            pcStack_a8 = pcStack_f8;
            pcStack_a0 = pcStack_f8;
            if (DAT_23ed6a498 == (longlong *)0x0) {
              plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
              if (plVar9 != (longlong *)0x0) {
                *plVar9 = *plVar9 + 1;
                DAT_23ed6a498 = plVar9;
                goto LAB_23e773a12;
              }
LAB_23e776bbd:
              plVar12 = in_R10;
              PyErr_PrintEx(0,0);
              lVar10 = Py_Exit();
LAB_23e776bd0:
              uVar18 = *(undefined8 *)(param_1 + 0x60);
              uVar19 = *(undefined8 *)(param_1 + 0x68);
              plVar13 = *(longlong **)(param_1 + 0x70);
LAB_23e776bd9:
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_c8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              auStack_d8 = (undefined1  [16])0x0;
              *plStack_130 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                FUN_23a334bc0();
              }
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plStack_108 = (longlong *)0x0;
              uVar17 = 0x59f;
              plStack_160 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              auStack_d8._8_8_ = uVar19;
              auStack_d8._0_8_ = uVar18;
              plVar8 = plStack_f0;
              plVar11 = plVar12;
              plStack_c8 = plVar13;
              goto LAB_23e7740e0;
            }
LAB_23e773a12:
            plStack_110 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,&uStack_b8);
            if (plStack_110 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x599;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            *(undefined4 *)(plVar3 + 5) = 0x59b;
            plStack_f0 = (longlong *)FUN_23e91bfe0(param_1,plVar1);
            if (plStack_f0 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x59b;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            plStack_150 = (longlong *)FUN_23e8bc2f0(plStack_f0,DAT_23ed6ce40);
            pcVar15 = DAT_23eed8db0;
            lVar10 = DAT_23ed6cce8;
            plVar8 = plStack_f0;
            if (plStack_150 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x59c;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            lVar2 = *(longlong *)(param_1 + 0x10);
            iVar7 = *(int *)(lVar2 + 0x1410);
            plVar9 = *(longlong **)(DAT_23ed6cce8 + 0x20);
            *plVar9 = *plVar9 + 1;
            if (iVar7 == 0) {
              pcVar16 = (code *)FUN_23a33a530(PyDict_Type_exref);
              plVar9 = *(longlong **)(lVar10 + 0x20);
            }
            else {
              iVar7 = iVar7 + -1;
              *(int *)(lVar2 + 0x1410) = iVar7;
              pcVar16 = *(code **)(lVar2 + 0x1190 + (longlong)iVar7 * 8);
              *(longlong *)pcVar16 = 1;
            }
            lVar10 = *(longlong *)(lVar10 + 0x28);
            *(longlong *)(pcVar16 + 0x10) = 0;
            *(longlong **)(pcVar16 + 0x20) = plVar9;
            *(longlong *)(pcVar16 + 0x28) = lVar10;
            *(longlong *)(pcVar16 + 0x18) = 1;
            *(undefined4 *)(plVar3 + 5) = 0x59c;
            pcStack_88 = pcVar15;
            pcStack_80 = pcVar16;
            plVar12 = (longlong *)FUN_23e94ed00(param_1,plStack_150);
            lVar10 = *plStack_150;
            *plStack_150 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              (**(code **)(plStack_150[1] + 0x30))(plStack_150);
            }
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
            if (*(longlong *)pcVar16 == 0) {
              (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
            }
            if (plVar12 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              uVar17 = 0x59c;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            iVar7 = PySequence_Contains(plVar12,DAT_23eed8db8);
            uVar18 = _DAT_23eed9618;
            pcVar15 = _DAT_23eed9610;
            plVar11 = plVar12;
            if (iVar7 == -1) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              uVar17 = 0x59d;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            if (iVar7 != 1) {
              plStack_160 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              plStack_158 = (longlong *)0x0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              goto LAB_23e773c64;
            }
            *(undefined4 *)(plVar3 + 5) = 0x59f;
            uStack_70 = uVar18;
            pcStack_78 = pcStack_f8;
            uStack_68 = DAT_23ed6ccf0;
            pcStack_88 = pcVar15;
            pcStack_80 = DAT_23eed8950;
            if (DAT_23ed6a498 == (longlong *)0x0) {
              in_R10 = plVar12;
              plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
              if (plVar9 == (longlong *)0x0) goto LAB_23e776bbd;
              *plVar9 = *plVar9 + 1;
              DAT_23ed6a498 = plVar9;
            }
            plStack_130 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,&pcStack_88);
            pcVar15 = PyModule_Type_exref;
            if (plStack_130 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_158 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar17 = 0x59f;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_130 = (longlong *)0x0;
              goto LAB_23e7740e0;
            }
            if (((code *)plStack_130[1] == PyModule_Type_exref) ||
               (iVar7 = PyType_IsSubtype((code *)plStack_130[1],PyModule_Type_exref), iVar7 != 0)) {
              uVar18 = DAT_23ed6ccf0;
              plStack_150 = (longlong *)
                            FUN_23e970d20(param_1,plStack_130,DAT_23eed8950,_DAT_23eed9620,
                                          DAT_23ed6ccf0);
              uVar17 = (undefined4)((ulonglong)uVar18 >> 0x20);
            }
            else {
              plStack_150 = (longlong *)FUN_23e8d2f70(param_1,plStack_130);
            }
            if (plStack_150 == (longlong *)0x0) {
              uVar18 = *(undefined8 *)(param_1 + 0x60);
              uVar19 = *(undefined8 *)(param_1 + 0x68);
              plVar13 = *(longlong **)(param_1 + 0x70);
              lVar10 = *plStack_130;
              goto LAB_23e776bd9;
            }
            if (((code *)plStack_130[1] == pcVar15) ||
               (iVar7 = PyType_IsSubtype((code *)plStack_130[1],pcVar15), iVar7 != 0)) {
              uVar18 = DAT_23ed6ccf0;
              plStack_118 = (longlong *)
                            FUN_23e970d20(param_1,plStack_130,DAT_23eed8950,_DAT_23eed9628,
                                          DAT_23ed6ccf0);
              uVar17 = (undefined4)((ulonglong)uVar18 >> 0x20);
            }
            else {
              plStack_118 = (longlong *)FUN_23e8d2f70(param_1,plStack_130);
            }
            lVar10 = *plStack_130;
            if (plStack_118 == (longlong *)0x0) goto LAB_23e776bd0;
            *plStack_130 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x5a0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_130 = (longlong *)0x0;
              goto LAB_23e7740e0;
            }
            iVar7 = FUN_23e913250(plVar9,DAT_23eed90d8);
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (iVar7 == -1) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar17 = 0x5a0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              plStack_130 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            if (iVar7 == 1) {
              plStack_130 = plStack_118;
              *plStack_118 = *plStack_118 + 1;
            }
            else {
              *plStack_150 = *plStack_150 + 1;
              plStack_130 = plStack_150;
            }
            plVar9 = (longlong *)FUN_23a388650(param_1,plStack_130,DAT_23ed6ccf0,0);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              uVar17 = 0x5a6;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_138 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            plVar13 = (longlong *)FUN_23a388650(param_1,plStack_130);
            if (plVar13 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar10 = *plVar9;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar9 = lVar10 + -1;
              pcStack_128 = (code *)0x0;
              if (lVar10 + -1 == 0) {
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                FUN_23a334bc0(plVar9);
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                uVar17 = 0x5a6;
                plStack_160 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_138 = (code *)0x0;
                pcStack_168 = (code *)0x0;
                goto LAB_23e7740e0;
              }
LAB_23e776eeb:
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plStack_100 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              uVar17 = 0x5a6;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            plVar14 = (longlong *)FUN_23e8c1ce0(plVar13,DAT_23eed8f30);
            lVar10 = *plVar13;
            *plVar13 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (plVar14 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar10 = *plVar9;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar9 = lVar10 + -1;
              pcStack_168 = (code *)0x0;
              if (lVar10 + -1 == 0) {
                FUN_23a334bc0(plVar9);
                pcVar15 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                uVar17 = 0x5a6;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_138 = (code *)0x0;
                pcStack_128 = (code *)0x0;
              }
              else {
                pcVar15 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                uVar17 = 0x5a6;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_138 = (code *)0x0;
                pcStack_128 = (code *)0x0;
              }
              goto LAB_23e7740e0;
            }
            pcStack_128 = (code *)FUN_23e8c09e0(plVar9,plVar14);
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar9);
            }
            lVar10 = *plVar14;
            *plVar14 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar14);
            }
            if (pcStack_128 == (code *)0x0) {
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e776eeb;
            }
            plVar13 = (longlong *)FUN_23a388650(param_1,plStack_130);
            if (plVar13 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_158 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_138 = (code *)0x0;
              pcStack_168 = (code *)0x0;
              uVar17 = 0x5a7;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_140 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            plVar9 = (longlong *)FUN_23a388650(param_1,plStack_130,_DAT_23eed9630);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar10 = *plVar13;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = lVar10 + -1;
              pcStack_168 = (code *)0x0;
              if (lVar10 + -1 == 0) {
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                FUN_23a334bc0(plVar13);
                plStack_100 = (longlong *)0x0;
                uVar17 = 0x5a7;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_138 = (code *)0x0;
                goto LAB_23e7740e0;
              }
LAB_23e7772d2:
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plStack_100 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x5a7;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            plVar14 = (longlong *)FUN_23e8c1ce0(plVar9,DAT_23eed8f30);
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar9);
            }
            if (plVar14 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar10 = *plVar13;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = lVar10 + -1;
              pcStack_138 = (code *)0x0;
              if (lVar10 + -1 == 0) {
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                FUN_23a334bc0(plVar13);
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                uVar17 = 0x5a7;
                plStack_160 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_168 = (code *)0x0;
              }
              else {
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                uVar17 = 0x5a7;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                pcStack_168 = (code *)0x0;
              }
              goto LAB_23e7740e0;
            }
            pcStack_168 = (code *)FUN_23e8c09e0(plVar13,plVar14);
            lVar10 = *plVar13;
            *plVar13 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar13);
            }
            lVar10 = *plVar14;
            *plVar14 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar14);
            }
            if (pcStack_168 == (code *)0x0) {
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7772d2;
            }
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_158 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar17 = 0x5a8;
              plStack_170 = (longlong *)0x0;
              pcStack_138 = (code *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_140 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            *(undefined4 *)(plVar3 + 5) = 0x5a8;
            pcStack_88 = pcStack_128;
            pcStack_80 = pcStack_168;
            plVar13 = (longlong *)FUN_23e954670(param_1,plVar9,DAT_23eed92c0,&pcStack_88);
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (plVar13 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x5a8;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_138 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            lVar10 = *plVar13;
            *plVar13 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar13);
            }
            *(undefined4 *)(plVar3 + 5) = 0x5a9;
            plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8c50);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              pcVar15 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar16 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              uVar17 = 0x5a9;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_138 = (code *)0x0;
              goto LAB_23e7740e0;
            }
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0(plVar9);
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(plStack_110,_DAT_23eed9638);
            if (plVar13 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x5ac;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              pcStack_138 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_170 = (longlong *)0x0;
              goto LAB_23e7740e0;
            }
            plVar9 = (longlong *)FUN_23e8bd350(plStack_120);
            if (plVar9 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar10 = *plVar13;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = lVar10 + -1;
              pcStack_140 = (code *)0x0;
              if (lVar10 + -1 == 0) {
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                FUN_23a334bc0(plVar13);
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                uVar17 = 0x5ac;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_138 = (code *)0x0;
              }
              else {
                pcVar15 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                pcVar16 = (code *)0x0;
                uVar17 = 0x5ac;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                pcStack_138 = (code *)0x0;
              }
              goto LAB_23e7740e0;
            }
            *(undefined4 *)(plVar3 + 5) = 0x5ac;
            pcStack_138 = (code *)FUN_23e914090(param_1,plVar13);
            lVar10 = *plVar13;
            *plVar13 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
            lVar10 = *plVar9;
            *plVar9 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (pcStack_138 == (code *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              plStack_100 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar9 = (longlong *)0x0;
              uVar17 = 0x5ac;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              pcStack_140 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            if (pcStack_138 != pcStack_f8) {
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
              if (plVar9 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                pcVar15 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
                uVar17 = 0x5ae;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                pcStack_140 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_170 = (longlong *)0x0;
                goto LAB_23e7740e0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x5ae;
              pcStack_140 = (code *)FUN_23e91bfe0(param_1,plVar9);
              lVar10 = *plVar9;
              *plVar9 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                FUN_23a334bc0(plVar9);
              }
              if (pcStack_140 == (code *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                uVar17 = 0x5ae;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7740e0;
              }
              if (pcStack_140 == pcStack_f8) {
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                goto LAB_23e773c64;
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(plStack_110,_DAT_23eed9640);
              if (plVar9 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                plStack_100 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                pcVar16 = (code *)0x0;
                uVar17 = 0x5b0;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                plStack_170 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar9 = (longlong *)0x0;
                goto LAB_23e7740e0;
              }
              pcVar15 = (code *)FUN_23e8bc2f0(plStack_110,_DAT_23eed9648);
              if (pcVar15 == (code *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar9 = *plVar9 + -1;
                plStack_158 = (longlong *)0x0;
                if (*plVar9 == 0) {
                  pcVar15 = (code *)0x0;
                  pcVar16 = (code *)0x0;
                  plVar9 = (longlong *)0x0;
                  FUN_23a334bc0();
                  uVar17 = 0x5b0;
                  plStack_100 = (longlong *)0x0;
                  plStack_108 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_170 = (longlong *)0x0;
                }
                else {
                  pcVar15 = (code *)0x0;
                  pcVar16 = (code *)0x0;
                  plStack_100 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  uVar17 = 0x5b0;
                  plStack_108 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_170 = (longlong *)0x0;
                }
                goto LAB_23e7740e0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x5b0;
              pcStack_88 = pcStack_140;
              pcStack_80 = pcStack_138;
              pcStack_78 = pcVar15;
              plStack_170 = (longlong *)FUN_23e956150(param_1,plVar9,&pcStack_88);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                FUN_23a334bc0(plVar9);
              }
              lVar10 = *(longlong *)pcVar15;
              *(longlong *)pcVar15 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                FUN_23a334bc0(pcVar15);
              }
              if (plStack_170 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                pcVar15 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar16 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
                uVar17 = 0x5b0;
                plStack_108 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                plStack_158 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7740e0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x5b1;
              plVar9 = (longlong *)FUN_23e915840(param_1,plStack_110,_DAT_23eed9650,plStack_170);
              if (plVar9 == (longlong *)0x0) {
LAB_23e778093:
                plVar12 = *(longlong **)(param_1 + 0x70);
                uVar18 = *(undefined8 *)(param_1 + 0x60);
                uVar19 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                plVar13 = (longlong *)FUN_23a388310(plVar9);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  FUN_23a334bc0(plVar9);
                }
                if (plVar13 == (longlong *)0x0) goto LAB_23e778093;
                uVar18 = CONCAT44(uVar17,4);
                plVar14 = (longlong *)FUN_23a3c1d30(param_1,auStack_d8,plVar13,0,uVar18);
                if (plVar14 == (longlong *)0x0) {
                  plVar9 = (longlong *)0x0;
                  plStack_160 = (longlong *)0x0;
                  plStack_158 = (longlong *)0x0;
                }
                else {
                  uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),4);
                  plVar9 = (longlong *)FUN_23a3c1d30(param_1,auStack_d8,plVar13,1,uVar18);
                  if (plVar9 == (longlong *)0x0) {
                    plStack_160 = (longlong *)0x0;
                    plStack_158 = (longlong *)0x0;
                  }
                  else {
                    uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),4);
                    plStack_158 = (longlong *)FUN_23a3c1d30(param_1,auStack_d8,plVar13,2,uVar18);
                    if (plStack_158 == (longlong *)0x0) {
                      plStack_160 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),4);
                      plStack_160 = (longlong *)FUN_23a3c1d30(param_1,auStack_d8,plVar13,3,uVar18);
                      uVar17 = (undefined4)((ulonglong)uVar18 >> 0x20);
                      if ((plStack_160 != (longlong *)0x0) &&
                         (cVar6 = FUN_23a3884a0(param_1,auStack_d8), cVar6 != '\0')) {
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        if (*plVar14 == 0) {
                          FUN_23a334bc0(plVar14);
                        }
                        if (*plVar9 == 0) {
                          FUN_23a334bc0(plVar9);
                        }
                        *plStack_158 = *plStack_158 + 1;
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0(plVar14);
                        }
                        lVar10 = *plStack_158;
                        *plStack_158 = lVar10 + -1;
                        if (lVar10 + -1 == 0) {
                          FUN_23a334bc0(plStack_158);
                        }
                        if (*plStack_160 == 0) {
                          FUN_23a334bc0();
                        }
                        iVar7 = FUN_23e97d950(plVar9,_DAT_23eed9658);
                        lVar10 = _DAT_23eed9678;
                        if (iVar7 == -1) {
                          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                          plStack_c8 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar17 = 0x5b2;
                          pcVar15 = (code *)0x0;
                          pcVar16 = (code *)0x0;
                          plStack_100 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e7740e0;
                        }
                        if (iVar7 != 1) {
                          *(undefined4 *)(plVar3 + 5) = 0x5ba;
                          plVar13 = (longlong *)
                                    FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                  *(undefined8 *)(lVar10 + 0x18));
                          if (plVar13 == (longlong *)0x0) {
                            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_c8 = *(longlong **)(param_1 + 0x70);
                            pcVar15 = (code *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pcVar16 = (code *)0x0;
                            uVar17 = 0x5ba;
                            plStack_100 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_108 = (longlong *)0x0;
                            goto LAB_23e7740e0;
                          }
                          lVar10 = *plVar13;
                          *plVar13 = lVar10 + -1;
                          if (lVar10 + -1 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          pcVar15 = (code *)0x0;
                          pcVar16 = (code *)0x0;
                          plStack_100 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          goto LAB_23e773c64;
                        }
                        plVar13 = (longlong *)FUN_23e8bc2f0(pcStack_138,_DAT_23eed9660);
                        if (plVar13 == (longlong *)0x0) {
LAB_23e778018:
                          uVar18 = *(undefined8 *)(param_1 + 0x60);
                          uVar19 = *(undefined8 *)(param_1 + 0x68);
                          plVar12 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                        }
                        else {
                          plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar13,_DAT_23eed9668);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          if (plVar14 == (longlong *)0x0) goto LAB_23e778018;
                          plVar13 = (longlong *)FUN_23a388310(plVar14);
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                          if (plVar13 == (longlong *)0x0) goto LAB_23e778018;
                          plStack_108 = (longlong *)
                                        FUN_23a3c1d30(param_1,auStack_d8,plVar13,0,
                                                      CONCAT44(uVar17,2));
                          if (plStack_108 == (longlong *)0x0) {
                            *plVar13 = *plVar13 + -1;
                            plStack_100 = (longlong *)0x0;
                            plVar12 = plStack_c8;
                            uVar18 = auStack_d8._0_8_;
                            uVar19 = auStack_d8._8_8_;
                            if (*plVar13 == 0) {
LAB_23e777f04:
                              plStack_c8 = (longlong *)0x0;
                              auStack_d8 = (undefined1  [16])0x0;
                              FUN_23a334bc0(plVar13);
                              plStack_c8 = (longlong *)0x0;
                              auStack_d8 = (undefined1  [16])0x0;
                              if (plStack_108 != (longlong *)0x0) goto LAB_23e777f4d;
                              goto LAB_23e777f91;
                            }
                          }
                          else {
                            plStack_100 = (longlong *)FUN_23a3c1d30(param_1,auStack_d8,plVar13,1,2);
                            if ((plStack_100 != (longlong *)0x0) &&
                               (cVar6 = FUN_23a3884a0(param_1,auStack_d8,plVar13,2), cVar6 != '\0'))
                            {
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0(plVar13);
                              }
                              if (*plStack_108 == 0) {
                                FUN_23a334bc0();
                              }
                              if (*plStack_100 == 0) {
                                FUN_23a334bc0();
                              }
                              plVar13 = (longlong *)
                                        FUN_23a388650(param_1,plStack_160,DAT_23ed6ccf0,0);
                              if (plVar13 == (longlong *)0x0) {
                                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                pcVar15 = (code *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcVar16 = (code *)0x0;
                                uVar17 = 0x5b4;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7740e0;
                              }
                              plVar14 = (longlong *)FUN_23e8c1ce0(plStack_100,DAT_23eed8f30);
                              if (plVar14 == (longlong *)0x0) {
                                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar13 = *plVar13 + -1;
                                pcVar15 = (code *)0x0;
                                if (*plVar13 == 0) {
                                  pcVar16 = (code *)0x0;
                                  FUN_23a334bc0(plVar13);
                                  uVar17 = 0x5b4;
                                }
                                else {
                                  pcVar16 = (code *)0x0;
                                  uVar17 = 0x5b4;
                                }
                                goto LAB_23e7740e0;
                              }
                              pcVar16 = (code *)FUN_23e8c09e0(plVar13,plVar14);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0(plVar13);
                              }
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              if (pcVar16 == (code *)0x0) {
                                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                pcVar15 = (code *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar17 = 0x5b4;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7740e0;
                              }
                              plVar13 = (longlong *)FUN_23a388650(param_1,plStack_160,DAT_23ed6ccf8)
                              ;
                              if (plVar13 == (longlong *)0x0) {
                                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar17 = 0x5b5;
                                pcVar15 = (code *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7740e0;
                              }
                              plVar14 = (longlong *)FUN_23e8c1ce0(plStack_108,DAT_23eed8f30);
                              if (plVar14 == (longlong *)0x0) {
                                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  pcVar15 = (code *)0x0;
                                  FUN_23a334bc0(plVar13);
                                  uVar17 = 0x5b5;
                                }
                                else {
                                  pcVar15 = (code *)0x0;
                                  uVar17 = 0x5b5;
                                }
                                goto LAB_23e7740e0;
                              }
                              pcVar15 = (code *)FUN_23e8c09e0(plVar13,plVar14);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0(plVar13);
                              }
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              if (pcVar15 == (code *)0x0) {
                                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar17 = 0x5b5;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e7740e0;
                              }
                              plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
                              if (plVar13 != (longlong *)0x0) {
                                *(undefined4 *)(plVar3 + 5) = 0x5b6;
                                pcStack_88 = pcVar16;
                                pcStack_80 = pcVar15;
                                plVar14 = (longlong *)FUN_23e954670(param_1,plVar13,DAT_23eed92c0);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (plVar14 != (longlong *)0x0) {
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  lVar10 = _DAT_23eed9670;
                                  *(undefined4 *)(plVar3 + 5) = 0x5b7;
                                  plVar13 = (longlong *)
                                            FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                          *(undefined8 *)(lVar10 + 0x18));
                                  if (plVar13 == (longlong *)0x0) {
                                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar17 = 0x5b7;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e7740e0;
                                  }
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0(plVar13);
                                  }
                                  lVar10 = DAT_23eed8ce0;
                                  *(undefined4 *)(plVar3 + 5) = 0x5b8;
                                  plVar13 = (longlong *)
                                            FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                                          *(undefined8 *)(lVar10 + 0x18));
                                  if (plVar13 == (longlong *)0x0) {
                                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar17 = 0x5b8;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e7740e0;
                                  }
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  goto LAB_23e773c64;
                                }
                              }
                              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plStack_c8 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar17 = 0x5b6;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23e7740e0;
                            }
                            *plVar13 = *plVar13 + -1;
                            plVar12 = plStack_c8;
                            uVar18 = auStack_d8._0_8_;
                            uVar19 = auStack_d8._8_8_;
                            if (*plVar13 == 0) goto LAB_23e777f04;
LAB_23e777f4d:
                            plStack_c8 = (longlong *)0x0;
                            auStack_d8 = (undefined1  [16])0x0;
                            lVar10 = *plStack_108;
                            *plStack_108 = lVar10 + -1;
                            if (lVar10 + -1 == 0) {
                              FUN_23a334bc0(plStack_108);
                            }
LAB_23e777f91:
                            if ((plStack_100 != (longlong *)0x0) &&
                               (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)
                               ) {
                              FUN_23a334bc0(plStack_100);
                            }
                          }
                        }
                        pcVar15 = (code *)0x0;
                        plStack_100 = (longlong *)0x0;
                        pcVar16 = (code *)0x0;
                        uVar17 = 0x5b3;
                        plStack_108 = (longlong *)0x0;
                        auStack_d8._8_8_ = uVar19;
                        auStack_d8._0_8_ = uVar18;
                        plStack_c8 = plVar12;
                        goto LAB_23e7740e0;
                      }
                    }
                  }
                }
                plVar12 = plStack_c8;
                uVar18 = auStack_d8._0_8_;
                uVar19 = auStack_d8._8_8_;
                auStack_d8 = (undefined1  [16])0x0;
                plStack_c8 = (longlong *)0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  FUN_23a334bc0(plVar13);
                }
                plStack_c8 = (longlong *)0x0;
                auStack_d8 = (undefined1  [16])0x0;
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  FUN_23a334bc0(plVar14);
                }
                if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                  FUN_23a334bc0(plVar9);
                }
                if ((plStack_158 != (longlong *)0x0) &&
                   (lVar10 = *plStack_158, *plStack_158 = lVar10 + -1, lVar10 + -1 == 0)) {
                  FUN_23a334bc0(plStack_158);
                }
                if ((plStack_160 != (longlong *)0x0) &&
                   (lVar10 = *plStack_160, *plStack_160 = lVar10 + -1, lVar10 + -1 == 0)) {
                  FUN_23a334bc0(plStack_160);
                }
              }
              uVar17 = 0x5b1;
              pcVar15 = (code *)0x0;
              pcVar16 = (code *)0x0;
              plStack_100 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_158 = (longlong *)0x0;
              auStack_d8._8_8_ = uVar19;
              auStack_d8._0_8_ = uVar18;
              plStack_c8 = plVar12;
              goto LAB_23e7740e0;
            }
            pcVar15 = (code *)0x0;
            pcVar16 = (code *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plStack_158 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            pcStack_140 = (code *)0x0;
LAB_23e773c64:
            cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_FalseStruct_exref);
            if (cVar6 == '\0') {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              uVar17 = 0x5bc;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7740e0;
            }
            lVar10 = FUN_23e8e0e20();
            if (lVar10 == 0) {
              FUN_23e915740(param_1,auStack_d8,DAT_23eed8988);
              uVar17 = 0x5bd;
              goto LAB_23e7740e0;
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eed8990);
            if (plVar13 != (longlong *)0x0) {
              cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar13);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (cVar6 != '\0') {
                lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar8 = *(longlong **)(lVar10 + 0x28);
                plVar3 = (longlong *)plVar8[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
                *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                if (plVar3 != (longlong *)0x0) {
                  plVar8[2] = 0;
                  *plVar3 = *plVar3 + -1;
                  if (*plVar3 == 0) {
                    (**(code **)(plVar3[1] + 0x30))();
                  }
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                plVar8[0xf] = 0;
                *(longlong *)pcStack_f8 = *(longlong *)pcStack_f8 + 1;
                lVar10 = *plStack_f0;
                *plStack_f0 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  (**(code **)(plStack_f0[1] + 0x30))();
                }
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                  lVar10 = *plStack_148;
                  *plStack_148 = lVar10 + -1;
                  if (lVar10 + -1 == 0) goto LAB_23e773e20;
LAB_23e773e2f:
                  if (plStack_120 != (longlong *)0x0) goto LAB_23e773e3a;
                }
                else {
                  lVar10 = *plStack_148;
                  *plStack_148 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
LAB_23e773e20:
                    (**(code **)(plStack_148[1] + 0x30))();
                    goto LAB_23e773e2f;
                  }
LAB_23e773e3a:
                  lVar10 = *plStack_120;
                  *plStack_120 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
                  }
                }
                if ((plStack_110 != (longlong *)0x0) &&
                   (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
                  (**(code **)(plStack_110[1] + 0x30))(plStack_110);
                }
                if ((plStack_150 != (longlong *)0x0) &&
                   (lVar10 = *plStack_150, *plStack_150 = lVar10 + -1, lVar10 + -1 == 0)) {
                  (**(code **)(plStack_150[1] + 0x30))(plStack_150);
                }
                goto LAB_23e773f80;
              }
            }
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            uVar17 = 0x5bd;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7740e0;
          }
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        plStack_100 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        pcVar16 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        uVar17 = 0x592;
        plStack_160 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        pcStack_140 = (code *)0x0;
        pcStack_138 = (code *)0x0;
        pcStack_168 = (code *)0x0;
        pcStack_128 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        goto LAB_23e7740e0;
      }
      plStack_c8 = *(longlong **)(param_1 + 0x70);
      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    plVar8 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    pcVar15 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    pcVar16 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar17 = 0x582;
    plStack_160 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    pcStack_140 = (code *)0x0;
    pcStack_138 = (code *)0x0;
    pcStack_168 = (code *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
LAB_23e7740e0:
    plVar13 = plStack_c8;
    plVar12 = DAT_23ed6a4f8;
    if (plStack_c8 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar13 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar13;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar12[2] = 0;
      plVar12[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar17;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar2 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      plVar13 = plVar12;
      if ((plStack_c8 != (longlong *)0x0) && (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
        (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
      }
    }
    else if ((longlong *)plStack_c8[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar17;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
      lVar2 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar13;
      *plVar13 = *plVar13 + 1;
      plVar13 = plVar12;
      if ((plStack_c8 != (longlong *)0x0) && (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
        (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
      }
    }
    plStack_c8 = plVar13;
    FUN_23e8bba40(plVar3,"ooooooooooooooooooooo",plVar1,plVar8,plVar11,plStack_148,plStack_120,
                  plStack_110,plStack_150,plStack_118,plStack_130,pcStack_128,pcStack_168,
                  pcStack_138,pcStack_140,plStack_170,plStack_158,plVar9,plStack_160,plStack_108,
                  plStack_100,pcVar16,pcVar15);
    if (_DAT_23eedad70 == plVar3) {
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      _DAT_23eedad70 = (longlong *)0x0;
    }
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar10 + 0x28);
    plVar12 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
    *(undefined4 *)(plVar3 + 8) = 0xffffffff;
    if (plVar12 != (longlong *)0x0) {
      plVar3[2] = 0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    plVar12 = plStack_c8;
    plVar3[0xf] = 0;
    uVar18 = auStack_d8._0_8_;
    uVar19 = auStack_d8._8_8_;
    auStack_d8 = (undefined1  [16])0x0;
    plStack_c8 = (longlong *)0x0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if ((plStack_148 != (longlong *)0x0) &&
       (lVar10 = *plStack_148, *plStack_148 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_148[1] + 0x30))(plStack_148);
    }
    if ((plStack_120 != (longlong *)0x0) &&
       (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_120[1] + 0x30))(plStack_120);
    }
    if ((plStack_110 != (longlong *)0x0) &&
       (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_110[1] + 0x30))(plStack_110);
    }
    if ((plStack_150 != (longlong *)0x0) &&
       (lVar10 = *plStack_150, *plStack_150 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_150[1] + 0x30))(plStack_150);
    }
    if ((plStack_118 != (longlong *)0x0) &&
       (lVar10 = *plStack_118, *plStack_118 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_118[1] + 0x30))(plStack_118);
    }
    if ((plStack_130 != (longlong *)0x0) &&
       (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_130[1] + 0x30))(plStack_130);
    }
    if ((pcStack_128 != (code *)0x0) &&
       (lVar10 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar10 + -1, lVar10 + -1 == 0)
       ) {
      (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
    }
    if ((pcStack_168 != (code *)0x0) &&
       (lVar10 = *(longlong *)pcStack_168, *(longlong *)pcStack_168 = lVar10 + -1, lVar10 + -1 == 0)
       ) {
      (**(code **)(*(longlong *)(pcStack_168 + 8) + 0x30))(pcStack_168);
    }
    if ((pcStack_138 != (code *)0x0) &&
       (lVar10 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar10 + -1, lVar10 + -1 == 0)
       ) {
      (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))(pcStack_138);
    }
    if ((pcStack_140 != (code *)0x0) &&
       (lVar10 = *(longlong *)pcStack_140, *(longlong *)pcStack_140 = lVar10 + -1, lVar10 + -1 == 0)
       ) {
      (**(code **)(*(longlong *)(pcStack_140 + 8) + 0x30))(pcStack_140);
    }
    if ((plStack_170 != (longlong *)0x0) &&
       (lVar10 = *plStack_170, *plStack_170 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_170[1] + 0x30))(plStack_170);
    }
    if ((plStack_158 != (longlong *)0x0) &&
       (lVar10 = *plStack_158, *plStack_158 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_158[1] + 0x30))(plStack_158);
    }
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if ((plStack_160 != (longlong *)0x0) &&
       (lVar10 = *plStack_160, *plStack_160 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_160[1] + 0x30))(plStack_160);
    }
    if ((plStack_108 != (longlong *)0x0) &&
       (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
    if ((plStack_100 != (longlong *)0x0) &&
       (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_100[1] + 0x30))(plStack_100);
    }
    if ((pcVar16 != (code *)0x0) &&
       (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
      (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
    }
    if ((pcVar15 != (code *)0x0) &&
       (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
      (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
    }
    *plVar1 = *plVar1 + -1;
    plStack_c8 = plVar12;
    auStack_d8._0_8_ = uVar18;
    auStack_d8._8_8_ = uVar19;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    FUN_23a33aa70(param_1,auStack_d8._0_8_,auStack_d8._8_8_,plStack_c8);
    return (code *)0x0;
  }
  plVar11 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  lVar10 = *(longlong *)_Py_NoneStruct_exref;
LAB_23e773290:
  pcStack_f8 = _Py_NoneStruct_exref;
  *(longlong *)_Py_NoneStruct_exref = lVar10 + 1;
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar9 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if (plVar8 == (longlong *)0x0) {
    plStack_108 = (longlong *)0x0;
    if (plVar11 == (longlong *)0x0) {
      pcVar15 = (code *)0x0;
      pcVar16 = (code *)0x0;
      goto LAB_23e7734c8;
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) goto LAB_23e77330f;
    pcVar15 = (code *)0x0;
    pcVar16 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
  }
  else {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      if (plVar11 != (longlong *)0x0) {
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          pcVar15 = (code *)0x0;
          pcVar16 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          (**(code **)(plVar11[1] + 0x30))(plVar11);
          pcStack_138 = (code *)0x0;
          pcStack_140 = (code *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_158 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_168 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
LAB_23e773f80:
          if ((plStack_118 != (longlong *)0x0) &&
             (lVar10 = *plStack_118, *plStack_118 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_118[1] + 0x30))(plStack_118);
          }
          if ((plStack_130 != (longlong *)0x0) &&
             (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_130[1] + 0x30))(plStack_130);
          }
          goto LAB_23e77337a;
        }
        pcStack_138 = (code *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        pcVar16 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        pcStack_168 = (code *)0x0;
        plStack_158 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        goto LAB_23e7733a5;
      }
      pcStack_140 = (code *)0x0;
      pcVar15 = (code *)0x0;
      plStack_108 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
LAB_23e773401:
      if ((pcStack_140 != (code *)0x0) &&
         (lVar10 = *(longlong *)pcStack_140, *(longlong *)pcStack_140 = lVar10 + -1,
         lVar10 + -1 == 0)) {
        (**(code **)(*(longlong *)(pcStack_140 + 8) + 0x30))(pcStack_140);
      }
    }
    else {
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
LAB_23e77330f:
        pcVar15 = (code *)0x0;
        pcVar16 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        pcStack_138 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_170 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        pcStack_168 = (code *)0x0;
        plStack_158 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
LAB_23e77337a:
        if ((pcStack_128 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
        }
LAB_23e7733a5:
        if ((pcStack_168 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_168, *(longlong *)pcStack_168 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_168 + 8) + 0x30))(pcStack_168);
        }
        plVar11 = plStack_100;
        if ((pcStack_138 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))(pcStack_138);
        }
        goto LAB_23e773401;
      }
      plVar11 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plStack_158 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
    }
    if ((plStack_170 != (longlong *)0x0) &&
       (lVar10 = *plStack_170, *plStack_170 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_170[1] + 0x30))(plStack_170);
    }
  }
  if ((plStack_158 != (longlong *)0x0) &&
     (lVar10 = *plStack_158, *plStack_158 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_158[1] + 0x30))(plStack_158);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plStack_160 != (longlong *)0x0) &&
     (lVar10 = *plStack_160, *plStack_160 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_160[1] + 0x30))(plStack_160);
  }
LAB_23e7734c8:
  if ((plStack_108 != (longlong *)0x0) && (*plStack_108 = *plStack_108 + -1, *plStack_108 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((pcVar16 != (code *)0x0) &&
     (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
    (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 != 0) {
    return pcStack_f8;
  }
  (**(code **)(plVar1[1] + 0x30))(plVar1);
  return pcStack_f8;
}
